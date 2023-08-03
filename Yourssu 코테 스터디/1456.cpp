#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P[10101010];
vector<int> primes;
void Sieve(int n = 1e7) {
	for (int i = 2; i * i <= n; i++) {
		if (P[i]) continue;
		primes.push_back(i);
		for (int j = i * i; j <= n; j += i) P[j] = 1;
	}
}

int main() {
	ll A, B, cnt = 0;
	Sieve();
	cin >> A >> B;
	for (int p : primes) {
		for (ll i = p * p; i <= B; i *= p) {
			if (i >= A) cnt++;
		}
	}
	cout << cnt;
}