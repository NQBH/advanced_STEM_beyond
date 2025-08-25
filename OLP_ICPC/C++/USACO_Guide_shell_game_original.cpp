#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;

int main() {
	freopen("shell.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> shell_at_pos(3); // shell_at_pos[i] stores the label of the shell located at position i
	for (int i = 0; i < 3; i++) shell_at_pos[i] = i; // Place the shells down arbitrarily
	vector<int> counter(3); // counter[i] stores the number of times the shell with label i was picked
	for (int i = 0; i < n; i++) {
		int a, b, g;
		scanf("%d %d %d", &a, &b, &g);		
		a--, b--, g--; // 0 indexing: offset all positions by 1
		std::swap(shell_at_pos[a], shell_at_pos[b]); // perform Bessie's swapping operation
		++counter[shell_at_pos[g]]; // count the number of times Elsie guesses each particular shell
	}
	freopen("shell.out", "w", stdout);
	printf("%d\n", std::max({counter[0], counter[1], counter[2]}));
}