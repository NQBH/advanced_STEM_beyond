#include <rl_tools/operations/cpu.h>  // Or use cuda.h for GPU
#include <rl_tools/rl/environments/environments.h>
#include <rl_tools/rl/algorithms/ppo/loop/core/config.h>
#include <rl_tools/rl/loop/steps/loop.h>
#include <rl_tools/random.h>
#include <rl_tools/math/math.h>
#include <rl_tools/utils/generic/typing.h>
#include <array>
#include <algorithm>
#include <cmath>

// Define parameters for JSSP (fixed 3 jobs, 3 machines)
template <typename T>
struct JSSPParameters {
    static constexpr int NUM_JOBS = 3;
    static constexpr int NUM_MACHINES = 3;
    static constexpr int MAX_OPS_PER_JOB = 3;  // Each job has up to 3 operations
    // Hardcoded routes: job[op] = machine
    std::array<std::array<int, MAX_OPS_PER_JOB>, NUM_JOBS> routes = {{
        {0, 1, 2},  // Job 0: Machine 0 -> 1 -> 2
        {1, 2, 0},  // Job 1: Machine 1 -> 2 -> 0
        {2, 0, 1}   // Job 2: Machine 2 -> 0 -> 1
    }};
    // Hardcoded processing times: job[op]
    std::array<std::array<T, MAX_OPS_PER_JOB>, NUM_JOBS> times = {{
        {3, 2, 5},  // Job 0 ops times
        {1, 4, 2},  // Job 1
        {4, 3, 1}   // Job 2
    }};
};

// Specification for the environment
template <typename T_T, typename T_TI, typename T_PARAMETERS = JSSPParameters<T_T>>
struct JSSPSpecification {
    using T = T_T;
    using TI = T_TI;
    using PARAMETERS = T_PARAMETERS;
};

// State struct
template <typename T, typename TI>
struct JSSPState {
    static constexpr TI NUM_JOBS = JSSPSpecification<T, TI>::PARAMETERS::NUM_JOBS;
    static constexpr TI NUM_MACHINES = JSSPSpecification<T, TI>::PARAMETERS::NUM_MACHINES;
    static constexpr TI MAX_OPS = JSSPSpecification<T, TI>::PARAMETERS::MAX_OPS_PER_JOB;
    std::array<TI, NUM_JOBS> job_progress;  // Current operation index for each job (0 to MAX_OPS)
    std::array<T, NUM_MACHINES> machine_free_time;  // Next available time for each machine
    T current_time = 0;  // Global time
};

// Observation: Flattened state for NN input (e.g., progress + free times + current time)
template <typename TI>
struct JSSPObservation {
    static constexpr TI DIM = JSSPState<float, TI>::NUM_JOBS + JSSPState<float, TI>::NUM_MACHINES + 1;
};

// Environment struct
template <typename T_SPEC>
struct JSSPEnv {
    using SPEC = T_SPEC;
    using T = typename SPEC::T;
    using TI = typename SPEC::TI;
    using Parameters = typename SPEC::PARAMETERS;
    using State = JSSPState<T, TI>;
    using Observation = JSSPObservation<TI>;
    static constexpr TI OBSERVATION_DIM = Observation::DIM;
    static constexpr TI ACTION_DIM = Parameters::NUM_JOBS * Parameters::NUM_MACHINES;  // Discrete actions: job-machine pairs (flatten)
    // For simplicity, assume discrete actions without masking; in practice, use action masking for invalid
};

// Namespace for RLtools integration
namespace rl_tools {
    // Reset: Initialize state
    template <typename DEVICE, typename SPEC, typename RNG>
    void sample_initial_state(DEVICE& device, const JSSPEnv<SPEC>& env, const typename JSSPEnv<SPEC>::Parameters& params, typename JSSPEnv<SPEC>::State& state, RNG& rng) {
        for (int j = 0; j < SPEC::PARAMETERS::NUM_JOBS; ++j) {
            state.job_progress[j] = 0;
        }
        for (int m = 0; m < SPEC::PARAMETERS::NUM_MACHINES; ++m) {
            state.machine_free_time[m] = 0;
        }
        state.current_time = 0;
    }

    // Observe: Convert state to observation vector
    template <typename DEVICE, typename SPEC, typename OBS_SPEC>
    void observe(DEVICE& device, const JSSPEnv<SPEC>& env, const typename JSSPEnv<SPEC>::State& state, Matrix<OBS_SPEC>& obs) {
        static_assert(OBS_SPEC::ROWS == 1 && OBS_SPEC::COLS == JSSPEnv<SPEC>::OBSERVATION_DIM);
        int idx = 0;
        for (int j = 0; j < SPEC::PARAMETERS::NUM_JOBS; ++j) {
            set(obs, 0, idx++, state.job_progress[j] / static_cast<typename SPEC::T>(SPEC::PARAMETERS::MAX_OPS_PER_JOB));  // Normalized
        }
        for (int m = 0; m < SPEC::PARAMETERS::NUM_MACHINES; ++m) {
            set(obs, 0, idx++, state.machine_free_time[m] - state.current_time);  // Relative free time
        }
        set(obs, 0, idx++, state.current_time / 100.0);  // Normalize arbitrary
    }

    // Step: Apply action, update state, return reward and terminal
    template <typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
    auto step(DEVICE& device, const JSSPEnv<SPEC>& env, const typename JSSPEnv<SPEC>::Parameters& params, const typename JSSPEnv<SPEC>::State& state, const Matrix<ACTION_SPEC>& action, typename JSSPEnv<SPEC>::State& next_state, RNG& rng) {
        // Action is discrete index: job = action_idx / NUM_MACHINES, machine = action_idx % NUM_MACHINES
        typename SPEC::TI action_idx = static_cast<typename SPEC::TI>(get(action, 0, 0));  // Assuming single discrete action
        typename SPEC::TI job = action_idx / SPEC::PARAMETERS::NUM_MACHINES;
        typename SPEC::TI machine = action_idx % SPEC::PARAMETERS::NUM_MACHINES;

        // Validate action (simple check; in practice, mask invalid)
        if (job >= SPEC::PARAMETERS::NUM_JOBS || state.job_progress[job] >= SPEC::PARAMETERS::MAX_OPS_PER_JOB ||
            params.routes[job][state.job_progress[job]] != machine) {
            // Invalid: penalty
            next_state = state;
            return std::make_tuple(typename SPEC::T(-10), false);  // Penalty reward, not terminal
        }

        // Schedule
        typename SPEC::TI op = state.job_progress[job];
        typename SPEC::T start_time = std::max(state.current_time, state.machine_free_time[machine]);
        typename SPEC::T process_time = params.times[job][op];
        typename SPEC::T end_time = start_time + process_time;

        next_state = state;
        next_state.job_progress[job]++;
        next_state.machine_free_time[machine] = end_time;
        next_state.current_time = end_time;  // Advance to next event (simplified; better to min over free times)

        // Check terminal
        bool terminal = true;
        for (int j = 0; j < SPEC::PARAMETERS::NUM_JOBS; ++j) {
            if (next_state.job_progress[j] < SPEC::PARAMETERS::MAX_OPS_PER_JOB) {
                terminal = false;
                break;
            }
        }

        // Reward: negative time advance + terminal bonus
        typename SPEC::T reward = -process_time;
        if (terminal) {
            reward -= next_state.current_time;  // Negative makespan
        }

        return std::make_tuple(reward, terminal);
    }
}

// Example main to train with PPO (adapt from RLtools examples)
int main() {
    using T = float;
    using TI = int;
    using ENV = JSSPEnv<JSSPSpecification<T, TI>>;
    using DEVICE = devices::DefaultCPU;

    DEVICE device;
    typename ENV::Parameters params;  // Default params

    // PPO config (simplified; see RLtools docs for full)
    using PPO_CONFIG = rl::algorithms::ppo::DefaultConfig<T, TI>;
    PPO_CONFIG ppo_config;
    // Set hyperparameters: actor/critic networks, etc.

    // Loop for training (use rl::loop::steps::loop from RLtools)
    // This would include actor, critic, buffers, etc.
    // For full example, refer to https://docs.rl.tools/06-Deep%20Reinforcement%20Learning.html

    // Pseudocode:
    // rl::rl::algorithms::ppo::ActorCritic<...> actor_critic;
    // Initialize, train loop with step, evaluate.

    return 0;
}