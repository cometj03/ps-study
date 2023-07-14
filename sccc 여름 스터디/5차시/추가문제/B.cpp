#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	if (a < b) return gcd(b, a);
	return gcd(b, a % b);
}

ll handsome_gcd(ll A[], int l, int r) {
	if (l > r) return 0;
	if (l == r) return A[l];
	int m = (l + r) / 2;
	int i = m - 1, j = m + 1, cnt = 1;
	ll res = A[m], g = A[m];
	while (i >= l && j <= r) {
		ll gcd_i = gcd(g, A[i]);
		ll gcd_j = gcd(g, A[j]);
		if (gcd_i > gcd_j)
			g = gcd_i, i--;
		else
			g = gcd_j, j++;
		cnt++;
		res = max(res, cnt * g);
	}
	while (i >= l) {
		cnt++;
		g = gcd(g, A[i--]);
		res = max(res, cnt * g);
	}
	while (j <= r) {
		cnt++;
		g = gcd(g, A[j++]);
		res = max(res, cnt * g);
	}
	res = max(res, handsome_gcd(A, l, m - 1));
	res = max(res, handsome_gcd(A, m + 1, r));
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		ll A[101010];
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		cout << handsome_gcd(A, 1, n) << '\n';
	}
}