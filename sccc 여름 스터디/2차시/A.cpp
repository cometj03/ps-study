#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define nbsp " "
int A[64][64], N;
int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};

bool Check(int x, int y, int size) {
	int tmp = A[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++)
			if (A[i][j] != tmp) return false;
	}
	return true;
}

void Quad(int x, int y, int size) {
	if (size == 1 || Check(x, y, size)) {
		cout << A[y][x];
		return;
	}
	cout << "(";
	for (int i = 0; i < 4; i++) {
		int s = size / 2;
		int mx = x + dx[i] * s;
		int my = y + dy[i] * s;
		Quad(mx, my, s);
	}
	cout << ")";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c;
		for (int j = 0; j < N; j++) {
			cin >> c;
			A[i][j] = c - '0';
		}
	}
	Quad(0, 0, N);
}