import java.util.*;
import java.math.*;
public class Main {
	static boolean[] go;
	static int[][] g; // adjacency matrix
	static int n, k; // numbers of vertices & arcs
	public static void find(int x) { // find all vertices reached from x
		go[x] = true;
		for (int i = 0; i < n; ++i)
			if (g[x][i] == 1 && !go[i]) find(i);
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			n = input.nextInt(); // number of vertices n & number of arcs k
			k = input.nextInt();
			if (n == 0) break;
			g = new int [n][n]; // initialize adjacency matrix
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) g[i][j] = 0;
			boolean doit = true; // mark of topological sort
			int[] f = new int [n + 1];
			for (int i = 1; i <= k; ++i) { // input & deal with k relations
				String p = input.next(); // k-th relation & vertices x, y
				int x = p.charAt(0) - 'A', c = p.charAt(1), y = p.charAt(2) - 'A';
				if (c == '>') {
					c = x;
					x = y;
					y = c;
				}
				go = new boolean[n];
				for (int j = 0; j < n; ++j) go[j] = false;
				if (doit) { // DFS start from y
					find(y);
					if (go[x]) { // if (x, y) is a back edge
						System.out.println("Inconsistency found after " + i + " relations.");
						doit = false;
						continue;
					}
					g[x][y] = 1;
					++f[y]; // in-degree of vertex y ++
					int[] Q = new int[n + 1];
					int tot = 0;
					for (int k = 0; k < n && tot <= 1; ++k)
						if (f[k] == 0) Q[++tot] = k;
					if (tot == 1) { // only 1 vertex whose in-degree is 0
						boolean finish = true;
						while (tot < n) {
							int xx = Q[tot], tmp = 0; // deleting arcs
							for (int k = 0; k < n; ++k)
								if (g[xx][k] == 1 && 0 == (f[k] -= g[xx][k])) {
									Q[++tot] = k;
									++tmp;
								}
							if (tmp > 1) {
								finish = false;
								break;
							}
						}
						if (finish && tot == n) { // there is a sorted sequence
							System.out.print("Sorted sequence determined after " + i + " relations: ");
							for (int k = 1; k <= n; ++k)
								System.out.print((char)('A' + Q[k]));
							System.out.println(".");
							doit = false;
						}
						for (int k = 0; k < n; ++k) f[k] = 0;
						for (int j = 0; j < n; ++j)
							for (int k = 0; k < n; ++k) f[k] += g[j][k];
					}
				}
			}
			if (doit) System.out.println("Sorted sequence cannot be determined.");
		}
	}
}