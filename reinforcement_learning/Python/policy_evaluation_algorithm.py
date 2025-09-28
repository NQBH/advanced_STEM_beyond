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

def policy_improvement(V, P, gamma = 1.0): # very simple algorithm. It takes the state-value function of the policy you want to improve, V, & the MDP, P (& gamma, optionally).
	Q = np.zeros((len(P), len(P[0])), dtype = np.float64) # Initialize the Q-function to 0 (technically, you can initialize these randomly, but let's keep things simple).
	for s in range(len(P)): # Then loop through the states, actions, & transitions.
		for a in range(len(P[s])):
			for prob, next_state, reward, done in P[s][a]: # done: Flag indicating whether next_state is terminal or not
				Q[s][a] += prob * (reward + gamma * V[next_state] * (not done)) # Use those values to calculate the Q-function.
	new_pi = lambda s: {s:a for s, a in enumerate(np.argmax(Q, axis = 1))}[s] # Finally, we obtain a new, greedy policy by taking the argmax of the Q-function of the original policy. & there, you have a likely improved policy.
	return new_pi

def policy_iteration(P, gamma = 1.0, theta = 1e-10): # Policy iteration is simple, & it only needs the MDP (including gamma).
	random_actions = np.random.choice(tuple(P[0].keys()), len(P))
	pi = lambda s: {s:a for s, a in enumerate(random_actions)}[s] # The 1st step is to create a randomly generated policy. Anything here should do. I create a list of random actions & then map them to states.
	while True:
		old_pi = {s:pi(s) for s in range(len(P))} # Keep a copy of the policy before we modify it.
		V = policy_evaluation(pi, P, gamma, theta) # Get the state-value function of the policy.
		pi = policy_improvement(V, P, gamma) # Get an improved policy.
		if old_pi == {s:pi(s) for s in range(len(P))}:
			break
		# If it is different, we do it all over again.
	return V, pi # If it is not, we break out of the loop & return an optimal policy & the optimal state-value function.

def value_iteration(P, gamma = 1.0, theta = 1e-10): # Like policy iteration, value iteration is a method for obtaining optimal policies. For this, we need an MDP (including gamma). Theta is the convergence criteria. 1e-10 is sufficiently accurate.
	V = np.zeros(len(P), dtype = np.float64) # 1st thing is to initialize a state-value function. Know that a V-function with random number should work fine.
	while True: # We get in this loop & initialize a Q-function to 0.
		Q = np.zeros((len(P), len(P[0])), dtype = np.float64) # Notice this one over here has to be zer0. Otherwise, the estimate would be incorrect.
		for s in range(len(P)): # Then, for every transition of every action in every state, we ...
			for a in range(len(P[s])):
				for porb, next_state, reward, done in P[s][a]:
					Q[s][a] += prob * (reward + gamma * V[next_state] * (not done)) # ... calculate the action-value function ... notice, using V, which is the old "truncated" estimate.
		if np.max(np.abs(V - np.max(Q, axis = 1))) < theta: # After each sweep over the state space, we make sure the state-value function keeps changing. Otherwise, we found the optimal V-function & should break out.
			break
		V = np.max(Q, axis = 1) # Thanks to this short line, we don't need a separate policy-improvement phase. It's not a direct replacement, but instead a combination of improvement & evaluation.
	pi = lambda s: {s:a for s, a in enumerate(np.argmax(Q, axis = 1))}[s]
	return V, pi # Only at the end do we extract the optimal policy & return it along with the optimal state-value function.
	