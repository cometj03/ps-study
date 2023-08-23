#include <bits/stdc++.h>
using namespace std;
int P[1010101], A[1010101];

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		A[i] = A[i - 1] + 1;
		P[i] = i - 1;
		if (i % 2 == 0 && A[i] > A[i / 2] + 1) {
			A[i] = A[i / 2] + 1;
			P[i] = i / 2;
		}
		if (i % 3 == 0 && A[i] > A[i / 3] + 1) {
			A[i] = A[i / 3] + 1;
			P[i] = i / 3;
		}
	}
	cout << A[N] << '\n';
	for (int i = N; i; i = P[i]) cout << i << ' ';
}