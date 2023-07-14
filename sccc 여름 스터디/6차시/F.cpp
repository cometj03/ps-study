#include <bits/stdc++.h>
using namespace std;
int Coin[101], D[10101];  // D[i] : i원을 만들 수 있는 최소 동전 개수

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> Coin[i];
	for (int i = 1; i <= K; i++) D[i] = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++)
			if (j - Coin[i] >= 0) D[j] = min(D[j], D[j - Coin[i]] + 1);
	}
	cout << (D[K] >= 1e9 ? -1 : D[K]);
}