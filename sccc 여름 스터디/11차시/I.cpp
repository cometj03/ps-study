#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, S;
vector<tuple<int, int, int>> E;	 // {weight, from, to}
vector<int> G[2020];

// Union find
int P[2020];
void Init() {
	for (int i = 1; i <= N; i++) P[i] = i;
}
int Find(int v) { return v == P[v] ? v : P[v] = Find(P[v]); }
bool Union(int u, int v) {
	int u_root = Find(u), v_root = Find(v);
	if (u_root == v_root) return false;
	P[v_root] = u_root;	 // P[P[v]] = P[u]랑 같음 Find 하면서 경로 축소 돼서
	return true;
}

ll Kruskal() {
	Init();
	ll res = 0;
	for (auto [w, u, v] : E) {
		if (Union(u, v)) res += w;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> S;
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E.emplace_back(w, u, v);
		G[u].push_back(v), G[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) cin >> S;	// 필요 없는 값 (순서 신경 안 써도 됨)
	sort(E.begin(), E.end());
	cout << Kruskal();
}