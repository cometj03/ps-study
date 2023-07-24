#include <bits/stdc++.h>
using namespace std;
int N, M, A[5050];

bool f(int n) {
	int block = 0, mn, mx;
	mx = mn = A[1];
	for (int i = 2; i <= N; i++) {
		mn = min(mn, A[i]);
		mx = max(mx, A[i]);
		if (mx - mn > n) {
			block++;
			mn = A[i];
			mx = A[i];
		}
	}
	block++;  // 마지막 블록
	return block <= M;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int l = 0, r = 1e4;
	while (l < r) {
		int m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m + 1;
	}
	cout << l;
}