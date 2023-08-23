#include <bits/stdc++.h>
using namespace std;
int N, DP[1010][3];	 // DP[i][j]: i번째 집을 j로 칠했을 때 최소 비용

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	int rgb[3];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) cin >> rgb[j];
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + rgb[0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + rgb[1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + rgb[2];
	}
	cout << min(DP[N][0], min(DP[N][1], DP[N][2]));
}