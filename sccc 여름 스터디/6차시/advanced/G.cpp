#include <bits/stdc++.h>
using namespace std;
int D[61][61][61], H[3], N;
int P[][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};

int solve(int x, int y, int z) {
	if (!x && !y && !z) return 0;
	int& res = D[x][y][z];
	if (res != -1) return res;

	res = 1e9;
	for (int i = 0; i < 6; i++) {
		int nx = x - P[i][0], ny = y - P[i][1], nz = z - P[i][2];
		nx = max(nx, 0);
		ny = max(ny, 0);
		nz = max(nz, 0);
		res = min(res, solve(nx, ny, nz) + 1);
	}
	return res;
}

int main() {
	memset(D, -1, sizeof(D));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	cout << solve(H[0], H[1], H[2]);
}