#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, A[10101];

ll f(int x) {
	ll res = 0;
	for (int i = 1; i <= N; i++) res += min(A[i], x);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int maximum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], maximum = max(A[i], maximum);
	cin >> M;
	int l = 0, r = maximum;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (f(mid) <= M)
			l = mid;
		else
			r = mid - 1;
	}
	cout << l;
}