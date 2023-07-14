#include <bits/stdc++.h>
using namespace std;
// D[i] : i원을 만드는 경우의 수
int D[10101], Coin[101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> Coin[i];
	D[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j - Coin[i] >= 0) D[j] += D[j - Coin[i]];
		}
	}
	cout << D[K];
}