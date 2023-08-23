#include <bits/stdc++.h>
using namespace std;
int A[1010];
int DP_UP[1010], DP_DOWN[1010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		DP_UP[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[i] > A[j]) DP_UP[i] = max(DP_UP[i], DP_UP[j] + 1);
	}
	for (int i = N; i >= 1; i--) {
		DP_DOWN[i] = 1;
		for (int j = N; j > i; j--)
			if (A[i] > A[j]) DP_DOWN[i] = max(DP_DOWN[i], DP_DOWN[j] + 1);
	}
	int mx = 0;
	for (int i = 1; i <= N; i++) mx = max(mx, DP_UP[i] + DP_DOWN[i] - 1);
	cout << mx;
}