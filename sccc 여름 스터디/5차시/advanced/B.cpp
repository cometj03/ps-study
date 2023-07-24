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
	ll res = 0;
	vector<pair<ll, ll>> leftGcd, rightGcd;	 // pair<gcd, index>
	leftGcd = rightGcd = {{A[m], m}};
	for (int i = m - 1; i >= l; i--) {
		ll g = gcd(A[i], leftGcd.back().first);
		if (g == leftGcd.back().first)
			leftGcd.back().second = i;
		else
			leftGcd.push_back(make_pair(g, i));
	}
	for (int i = m + 1; i <= r; i++) {
		ll g = gcd(A[i], rightGcd.back().first);
		if (g == rightGcd.back().first)
			rightGcd.back().second = i;
		else
			rightGcd.push_back(make_pair(g, i));
	}

	for (auto left : leftGcd)
		for (auto right : rightGcd)
			res = max(res, gcd(left.first, right.first) * (right.second - left.second + 1));

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