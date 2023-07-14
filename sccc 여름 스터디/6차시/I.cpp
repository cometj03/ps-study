#include <bits/stdc++.h>
using namespace std;
int D[1010101], P[1010101];

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		P[i] = i - 1;
		if (i % 2 == 0 && D[i] > D[i / 2] + 1) {
			D[i] = D[i / 2] + 1;
			P[i] = i / 2;
		}
		if (i % 3 == 0 && D[i] > D[i / 3] + 1) {
			D[i] = D[i / 3] + 1;
			P[i] = i / 3;
		}
	}
	cout << D[N] << '\n';
	for (int i = N; i > 0; i = P[i]) cout << i << ' ';
}