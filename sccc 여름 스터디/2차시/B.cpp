#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define nbsp " "
int N, R, C;
int D[2][2] = {0, 1, 2, 3};

int z(int x, int y, int size, int start) {
	if (size == 1) return start;
	int s = size / 2, nx = x, ny = y;
	int dx = 0, dy = 0;
	if (C >= x + s) {
		nx += s;
		dx = 1;
	}
	if (R >= y + s) {
		ny += s;
		dy = 1;
	}
	start += s * s * D[dy][dx];
	return z(nx, ny, s, start);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> R >> C;
	cout << z(0, 0, 1 << N, 0);
}