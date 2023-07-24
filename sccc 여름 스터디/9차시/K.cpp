#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int A[1010][1010], D[1010][1010], N, M;

int main() {
	pair<int, int> start;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if (A[i][j] != 0) D[i][j] = -1;
			if (A[i][j] == 2) start = {j, i};
		}
	}
	queue<pair<int, int>> Q;
	auto [x, y] = start;
	Q.emplace(x, y);
	D[y][x] = 0;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > M || ny > N) continue;
			if (A[ny][nx] && D[ny][nx] == -1) {
				Q.emplace(nx, ny);
				D[ny][nx] = D[y][x] + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cout << D[i][j] << ' ';
		cout << '\n';
	}
}