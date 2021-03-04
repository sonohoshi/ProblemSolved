#pragma warning(disable:4996)
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<vector<int>> adj, vector<bool>& visited, int node) {
	visited[node] = true;
	printf("%d ", node);
	for (auto n : adj[node]) {
		if (!visited[n]) DFS(adj, visited, n);
	}
}

void BFS(vector<vector<int>> adj, vector<bool>& visited, int node) {
	queue<int> q;

	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int here = q.front();

		printf("%d ", here);
		q.pop();

		for (auto n : adj[here]) {
			if (!visited[n]) {
				visited[n] = true;
				q.push(n);
			}
		}
	}
}

int main() {
	int n, m, v;
	scanf("%d%d%d", &n, &m, &v);
	vector<vector<int>> nodes;
	vector<bool> visited;

	nodes.resize(n + 1);
	visited.resize(n + 1, false);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		nodes[x].push_back(y);
		nodes[y].push_back(x);
	}

	for (int i = 0; i < nodes.size(); i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	DFS(nodes, visited, v);

	visited = vector<bool>(n + 1, false);
	puts("");
	BFS(nodes, visited, v);

	return 0;
}