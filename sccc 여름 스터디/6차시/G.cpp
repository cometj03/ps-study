// 0/1 Knapsack
#include <bits/stdc++.h>
using namespace std;
int V[101], W[101];
int D[101010];	// D[i]: 총 무게가 i 이하인 조합 중 최대의 가치

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];
	for (int i = 1; i <= N; i++) {
		// i번째 물품을 중복해서 가져갈 수 없어서 역순으로 처리함
		for (int j = K; j >= 1; j--)
			if (j - W[i] >= 0) D[j] = max(D[j], D[j - W[i]] + V[i]);
	}
	cout << D[K];
}