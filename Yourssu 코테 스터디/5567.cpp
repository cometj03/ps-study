#include <bits/stdc++.h>
using namespace std;
vector<int> G[505];
int visited[505], N, M, cnt = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int u, w;
		cin >> u >> w;
		G[u].push_back(w), G[w].push_back(u);
	}

	queue<pair<int, int>> Q;
	Q.emplace(1, 0);
	visited[1] = 1;
	while (!Q.empty()) {
		auto [i, depth] = Q.front();
		Q.pop();
		if (depth == 2) continue;
		for (int it : G[i])
			if (!visited[it]) {
				Q.emplace(it, depth + 1);
				cnt++;
				visited[i] = 1;
			}
	}
	cout << cnt;
}