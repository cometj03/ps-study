#include <bits/stdc++.h>
using namespace std;
int A[101010], D[101010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int mx = A[1];
	for (int i = 1; i <= N; i++) {
		D[i] = max(0, D[i - 1]) + A[i];
		mx = max(mx, D[i]);
	}
	cout << mx;
}