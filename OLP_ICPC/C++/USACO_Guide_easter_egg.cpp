#include <bits/stdc++.h>
using namespace std;

int findEgg(int N, vector<pair<int, int>> bridges);
int query(vector < int > islands);

vector<int> graph[513], ord;

void dfs(int node = 1, int parent = 0) {
	ord.push_back(node);
	for (int i : graph[node])
		if (i != parent) dfs(i, node);
}

int findEgg(int N, vector<pair<int, int>> bridges) {
	for (int i = 1; i <= N; ++i) graph[i].clear();
	ord.clear();
	for (pair<int, int> i : bridges) {
		graph[i.first].push_back(i.second);
		graph[i.second].push_back(i.first);
	}
	dfs();
	int l = 0, r = N - 1;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		if (query(vector<int>(ord.begin(), ord.begin() + mid))) r = mid - 1;
		else l = mid;
	}
	return ord[l];
}

static int N, X, cntQ;
static vector < int > v[1009];

int query (vector < int > h)
{
	cntQ ++;
	int ap[1009];
	if (h.empty ()) return 0;
	for (int i = 1; i <= N; i++)
		ap[i] = 0;
	for (auto it = h.begin (); it != h.end (); it ++)
		ap[*it] = 1;
	queue < int > cc;
	cc.push (h[0]), ap[h[0]] = 2;
	while (!cc.empty ())
	{
		int nod = cc.front ();
		cc.pop ();
		for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
			if (ap[*it] == 1)
				ap[*it] = 2, cc.push (*it);
	}
	for (int i = 1; i <= N; i++)
		if (ap[i] == 1) return -1;
	for (auto it = h.begin (); it != h.end (); it ++)
		if (*it == X) return 1;
	return 0;
}

/*
int findEgg (int N, vector < pair < int, int > > bridges)
{
    if (query ({1})) return 1;
    return N;
}
*/

int main ()
{
	freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

	scanf ("%d", &N);
	int Queries;
	vector < pair < int, int > > param;
	for (int i = 1; i < N; i++)
	{
		int x, y;
		scanf ("%d %d", &x, &y);
		v[x].push_back (y);
		v[y].push_back (x);
		param.push_back ({x, y});
	}
	scanf ("%d", &Queries);
	while (Queries --)
	{
		scanf ("%d", &X), cntQ = 0;
		int Y = findEgg (N, param);
		if (X != Y)
		{
			printf ("WA %d instead of %d\n", Y, X);
			return 0;
		}
		printf ("OK %d\n", cntQ);
	}
	return 0;
}