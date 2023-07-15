#include <bits/stdc++.h>
using namespace std;
int D[101][101][101];

int main() {
	string A, B, C;
	cin >> A >> B >> C;
	int N = A.length(), M = B.length(), K = C.length();
	A = "#" + A;
	B = "#" + B;
	C = "#" + C;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= K; k++) {
				if (A[i] == B[j] && B[j] == C[k])
					D[i][j][k] = D[i - 1][j - 1][k - 1] + 1;
				else {
					int mx = max(D[i - 1][j][k], D[i][j - 1][k]);
					mx = max(mx, D[i][j][k - 1]);
					D[i][j][k] = mx;
				}
			}
		}
	}
	cout << D[N][M][K];
}