// 맞왜틀?
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P[10101010];
vector<int> primes;
void Sieve(int n = 1e7) {
	P[0] = P[1] = 1;
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
	for (auto it : primes) {
		for (ll i = it * it; i <= B; i *= it) {
			if (i >= A) cnt++;
		}
	}
	cout << cnt;
}