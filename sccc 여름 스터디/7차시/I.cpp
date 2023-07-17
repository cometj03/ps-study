#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;
const int mod = 1'000'000'007;
int N, M, D;

matrix Mul(matrix& A, matrix& B) {
	matrix C(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
			}
		}
	}
	return C;
}

matrix Pow(matrix& m, int D) {
	if (D == 1) return m;
	matrix mm = Pow(m, D / 2);
	matrix mul = Mul(mm, mm);
	if (D % 2 == 0) {
		return mul;
	} else {
		return Mul(m, mul);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	matrix m(N, vector<ll>(N));
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		m[b - 1][a - 1] = m[a - 1][b - 1] = 1;
	}
	cin >> D;
	cout << Pow(m, D)[0][0];
}