#include <bits/stdc++.h>
using namespace std;
int N, M, S[50505];
// D[i][j] : i번째 소형 기관차가 j번째 객차까지 봤을 때,
// 최대로 운송할 수 있는 승객 수
int D[4][50505];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		S[i] = S[i - 1] + a;
	}
	cin >> M;

	for (int i = 1; i <= 3; i++) {
		for (int j = M * i; j <= N; j++) {
			D[i][j] = max(D[i][j - 1], D[i - 1][j - M] + S[j] - S[j - M]);
		}
	}
	cout << D[3][N];
}