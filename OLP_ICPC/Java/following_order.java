import java.util.*;
import java.io.Reader;
import java.io.Writer;
import java.math.*;
public class Main {
	public static void print(String x) { // print(x): output Topological Sort x
		System.out.print(x);
	}
	static int n; // numbr of vertices n
	static int[] pre;
	static boolean[] has;
	static String var, v;
	static void dfs(int dep, String res) { // dfs(dep, res) used to get topological sorts
		if (dep == n + 1) { // a topological sort is gotten
			print(res + "\n");
			return;
		}
		for (int i = 'a'; i <= 'z'; ++i) // search a vertex whose in-degree is 0
			if (has[i] && pre[i] == 0) {
				has[i] = false;
				for (int k = 0; k < v.length(); k += 4) // delete arcs starting from the vertex
					if (v.charAt(k) == i) --pre[v.charAt(k + 2)];
				dfs(dep + 1, res + (char)i); // the dep + 1-th vertex
				for (int k = 0; k < v.length(); k += 4) // recovery
					if (v.charAt(k) == i) ++pre[v.charAt(k + 2)];
				has[i] = true;

			}
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in); // java standard input
		while (input.hasNextLine()) {
			var = input.nextLine(); // input a list of variables
			v = input.nextLine(); // input a list of constraints
			has = new boolean[1 << 8];
			for (int i = 0; i < var.length(); i += 2)
				has[var.charAt(i)] = true;
			n = var.length() / 2 + 1; // number of vertices
			pre = new int[1 << 8];
			for (int i = 0; i < v.length(); i += 4) // calculate every vertices' in-degrees
				++pre[v.charAt(i + 2)];
			dfs(1, "");
			print("/n");
		}
	}
}