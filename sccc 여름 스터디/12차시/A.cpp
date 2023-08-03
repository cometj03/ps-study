#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int inf = 1e9;
int V, E, K, C[20202], D[20202];
vector<PII> G[20202];
priority_queue<PII, vector<PII>, greater<>> Q;	// {dist, v}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> E >> K;
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
	}

	for (int i = 1; i <= V; i++) D[i] = inf;
	D[K] = 0;
	Q.emplace(0, K);
	while (!Q.empty()) {
		auto [_, v] = Q.top();
		Q.pop();
		if (C[v]) continue;
		C[v] = 1;
		for (auto [u, w] : G[v]) {
			if (D[u] > D[v] + w) {
				D[u] = D[v] + w;
				Q.emplace(D[u], u);
			}
		}
	}
	for (int i = 1; i <= V; i++) cout << (D[i] == inf ? "INF" : to_string(D[i])) << '\n';
}