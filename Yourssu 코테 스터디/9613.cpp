#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void Solve() {
	ll ans = 0;
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v) cin >> i;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) ans += gcd(v[i], v[j]);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) Solve();
}