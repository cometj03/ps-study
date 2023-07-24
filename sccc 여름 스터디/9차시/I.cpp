#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int A[101][101], D[101][101], N, M;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) A[i][j] = s[j - 1] - '0';
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) D[i][j] = -1;

	queue<pair<int, int>> Q;
	Q.emplace(1, 1);  // Q.push({1, 1});
	D[1][1] = 1;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (A[ny][nx] == 1 && D[ny][nx] == -1) {
				D[ny][nx] = D[y][x] + 1;
				Q.emplace(nx, ny);
			}
		}
	}
	cout << D[N][M];
}