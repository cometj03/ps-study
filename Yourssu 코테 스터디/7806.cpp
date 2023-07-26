// 시간초과..
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (!cin.eof()) {
		int n, k, ans = 1;
		cin >> n >> k;
		while (k > 1 && n > 0) {
			int g = __gcd(n--, k);
			k /= g;
			ans *= g;
		}
		cout << ans << '\n';
	}
}