#include <bits/stdc++.h>
using namespace std;
int P[101010];
void Sieve(int n = 100'000) {
	P[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (P[i] == 0) {
			for (int j = i + i; j <= n; j += i) P[j] = 1;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	Sieve();
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 2; i <= n; i++) {
			int cnt = 0;
			while (P[i] == 0 && n % i == 0) cnt++, n /= i;
			if (cnt != 0) cout << i << ' ' << cnt << '\n';
		}
	}
}