#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int M, N, K, A[55][55];
bool visited[55][55];

void dfs(int x, int y) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (A[ny][nx] && !visited[ny][nx]) dfs(nx, ny);
	}
}

void Solve() {
	memset(A, 0, sizeof(A));
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	cin >> M >> N >> K;
	for (int i = 1; i <= K; i++) {
		int a, b;
		cin >> a >> b;
		A[b][a] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] && !visited[i][j]) dfs(j, i), cnt++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) Solve();
}