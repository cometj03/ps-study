#include <bits/stdc++.h>
using namespace std;
int A[1010][1010], N, x, y;
int dx[] = {0, 1, 0, 1}, dy[] = {0, 0, 1, 1};

int cnt = 1;

// (x1, y1)으로 시작하는 가로x세로 n인 블록에서
// exceptIdx 부분의 작은 블록 제외한 부분 채우기
// 순서:
// 2 3
// 0 1
void fill(int n, int x1, int y1, int exceptIdx) {
	if (n <= 2) {
		for (int i = 0; i < 4; i++) {
			if (i == exceptIdx) continue;
			int nx = x1 + dx[i], ny = y1 + dy[i];
			A[nx][ny] = cnt;
		}
		cnt++;
		return;
	}
	n /= 2;
	for (int i = 0; i < 4; i++) {
		if (i == exceptIdx) continue;
		int nx = x1 + dx[i] * n;
		int ny = y1 + dy[i] * n;
		fill(n, nx, ny, 3 - i);
	}
	int nx = x1 + n / 2;
	int ny = y1 + n / 2;
	fill(n, nx, ny, exceptIdx);
}

// -1 부분 포함하는 블록 채울 때
void sol(int n, int x1, int y1) {
	if (n == 1) return;
	n /= 2;
	for (int i = 0; i < 4; i++) {
		int nx = x1 + dx[i] * n;
		int ny = y1 + dy[i] * n;
		if ((nx <= x && x < nx + n) && (ny <= y && y < ny + n)) {
			sol(n, nx, ny);
			fill(n * 2, x1, y1, i);
		}
	}
}

int main() {
	cin >> N >> x >> y;
	A[x][y] = -1;
	N = 1 << N;
	sol(N, 1, 1);
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= N; j++) cout << A[j][i] << ' ';
		cout << '\n';
	}
}