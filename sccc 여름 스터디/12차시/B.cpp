#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int N, M, D[1010], C[1010], P[1010], from, to;
vector<pair<int, int>> G[1010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		G[a].emplace_back(b, w);
	}
	cin >> from >> to;

	for (int i = 1; i <= N; i++) D[i] = inf;
	D[from] = 0;
	P[from] = 0;
	for (int i = 1; i <= N; i++) {
		int v = -1;
		for (int j = 1; j <= N; j++) {
			if (C[j]) continue;
			if (v == -1 || D[v] > D[j]) v = j;
		}
		C[v] = 1;
		for (auto [u, w] : G[v]) {
			if (!C[u] && D[u] > D[v] + w) {
				D[u] = D[v] + w;
				P[u] = v;
			}
		}
	}
	vector<int> path;
	for (int i = to; i != 0; i = P[i]) path.push_back(i);
	reverse(path.begin(), path.end());
	cout << D[to] << '\n' << path.size() << '\n';
	for (int i : path) cout << i << ' ';
}