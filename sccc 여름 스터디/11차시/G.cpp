#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int V, E, P[10101];

// 서로소 집합
void Init() {
	for (int i = 1; i <= V; i++) P[i] = i;
}
int Find(int v) {
	if (v == P[v]) return v;
	return P[v] = Find(P[v]);
}
void Union(int u, int v) {
	int root1 = Find(u), root2 = Find(v);
	if (root1 != root2) P[root2] = root1;
}

ll Kruskal(vector<tuple<int, int, int>>& edge) {
	Init();
	ll res = 0;
	for (auto [a, b, w] : edge) {
		if (Find(a) != Find(b)) Union(a, b), res += w;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> E;
	vector<tuple<int, int, int>> edge(E);  // {start, end, weight}
	for (auto& [a, b, c] : edge) cin >> a >> b >> c;
	sort(edge.begin(), edge.end(), [](auto& a, auto& b) {
		auto [a1, a2, w1] = a;
		auto [b1, b2, w2] = b;
		return w1 < w2;
	});
	cout << Kruskal(edge);
}