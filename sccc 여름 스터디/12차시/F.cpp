#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector<pair<int, int>> G[303];
int N, Q, D[303][303][303];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int& a = D[0][i][j];
			cin >> a;
			if (a == 0 && i != j) a = inf;
		}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				D[k][i][j] = min(D[k - 1][i][j], D[k - 1][i][k] + D[k - 1][k][j]);
		}
	}
	while (Q--) {
		int c, s, e;
		cin >> c >> s >> e;
		cout << (D[c - 1][s][e] == inf ? -1 : D[c - 1][s][e]) << '\n';
	}
}