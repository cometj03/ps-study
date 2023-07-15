#include <bits/stdc++.h>
using namespace std;
// D[i][j]: i자리수 중 j로 시작하는 계단수의 개수
int D[101][10];
const int mod = 1e9;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= 9; i++) D[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][1];
		D[i][9] = D[i - 1][8];
		for (int j = 1; j <= 8; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
		}
	}
	int res = 0;
	for (int i = 1; i <= 9; i++) res = (res + D[N][i]) % mod;
	cout << res;
}