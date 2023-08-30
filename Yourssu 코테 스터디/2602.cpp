#include <bits/stdc++.h>
using namespace std;
vector<int> G[101];
int V, E, visited[101], cnt = 0;

void dfs(int cur) {
	visited[cur] = 1;
	cnt++;
	for (int i : G[cur])
		if (!visited[i]) dfs(i);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		int u, w;
		cin >> u >> w;
		G[u].push_back(w), G[w].push_back(u);
	}
	dfs(1);
	cout << cnt - 1;
}