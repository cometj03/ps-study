#include <bits/stdc++.h>
using namespace std;
// D[i] : i 번째까지의 LIS의 최대 길이
int A[1010], D[1010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, mx = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[i] > A[j]) D[i] = max(D[i], D[j] + 1);
		mx = max(mx, D[i]);
	}
	cout << mx;
}
