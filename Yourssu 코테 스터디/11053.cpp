#include <bits/stdc++.h>
using namespace std;
int A[1010], DP[1010], N;  // DP[i] : A[i]까지의 LIS의 최대 길이

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int mx = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		DP[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) DP[i] = max(DP[i], DP[j] + 1);
		}
		mx = max(mx, DP[i]);
	}
	cout << mx;
}