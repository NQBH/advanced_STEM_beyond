import numpy as np

def policy_evaluation(pi, P, gamma = 1.0, theta = 1e-10): # This is a full implementation of the policy-evaluation algorithm. All we need is the policy we are trying to evaluate & the MDP the policy runs on. The discount factor, gamma, defaults to 1, & theta is a small number that we use to check for convergence.
	prev_V = np.zeros(len(P)) # Here we initialize the 1st-iteration estimates of the state-value function to 0.
	while True: # begin by looping "foreover"
		V = np.zeros(len(P)) # We initialize the current-iteration estimates to 0 as well.
		for s in range(len(P)): # & then loop through all states to estimate the state-value function.
			for prob, next_state, reward, done in P[s][pi[s]]: # See how we use the policy pi to get the possble transitions. Each transition tuple has a probability, next state, reward, & a done flag indicating whether the 'next_state' is terminal or not.
				V[s] += prob * (reward + gamma * prev_V[next_state] * (not done)) # We calculate the value of that state by summing up the weighted value of that transition. Notice how we use the 'done' flag to ensure the value of the next state when landing on a terminal state is 0. We don't want infinite sums.
		if np.max(np.abs(prev_V - V)) < theta:
			break # At the end of each iteration (a state sweep), we make sure that the state-value functions are changing; otherwise, we call it converged.
		prev_V = V.copy() # Finally, "copy" to get ready for the next iteration or return the latest state-value function.
	return V