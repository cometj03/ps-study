#include <bits/stdc++.h>
using namespace std;
int N, R, Q, S[101010];
vector<int> G[101010];

void dfs(int v, int b = -1) {
	// b는 부모 정점
	// G가 트리이기 때문에 이렇게 방문 처리하는 것이 가능함
	S[v] = 1;
	for (auto w : G[v])
		if (w != b) dfs(w, v), S[v] += S[w];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> R >> Q;
	int u, v;
	for (int i = 1; i < N; i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
	dfs(R);
	while (Q--) {
		int n;
		cin >> n;
		cout << S[n] << '\n';
	}
}