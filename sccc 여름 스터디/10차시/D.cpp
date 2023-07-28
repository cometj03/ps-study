#include <bits/stdc++.h>
using namespace std;
int N, R, Q, DP[101010], visited[101010];
vector<int> G[101010];

void dfs(int n) {
	visited[n] = 1;
	if (G[n].empty()) {
		DP[n] = 1;
		return;
	}
	int cnt = 0;
	for (auto w : G[n]) {
		if (!visited[w]) dfs(w);
		cnt += DP[w];
	}
	DP[n] = 1 + cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(R);
	while (Q--) {
		int n;
		cin >> n;
		cout << DP[n] << '\n';
	}
}