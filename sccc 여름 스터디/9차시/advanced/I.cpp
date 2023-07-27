#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int A[1010][1010], visited[1010][1010], M, N;

bool AnyZeros() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (A[i][j] == 0) return true;
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) cin >> A[i][j];

	queue<pair<int, int>> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j] != 1) continue;
			visited[i][j] = 1;
			Q.emplace(j, i);
		}
	}

	int maxDay = 0;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();
		maxDay = max(maxDay, A[y][x]);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > M || ny > N) continue;
			if (A[ny][nx] == 0 && !visited[ny][nx]) {
				Q.emplace(nx, ny);
				visited[ny][nx] = 1;
				A[ny][nx] = A[y][x] + 1;
			}
		}
	}

	if (AnyZeros())
		cout << -1;
	else
		cout << maxDay - 1;
}