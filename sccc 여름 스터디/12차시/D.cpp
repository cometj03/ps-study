#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int D[101][101], N, M;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (i != j) D[i][j] = inf;
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		D[a][b] = min(D[a][b], c);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << (D[i][j] == inf ? 0 : D[i][j]) << ' ';
		cout << '\n';
	}
}