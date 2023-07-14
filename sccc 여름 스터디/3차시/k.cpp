#include <iostream>
using namespace std;
using ll = long long;
// SP[x] : x의 가장 작은 소인수
// E[x] : x에 SP[x]가 몇번 곱해졌는지
int SP[1010101], E[1010101];
ll Sigma[1010101];
ll Sum[1010101];

ll Pow(int a, int b) {
	ll res = 1;
	for (int i = 1; i <= b; i++) res *= a;
	return res;
}

ll GetSigma(int p, int e) { return (Pow(p, e + 1) - 1) / (p - 1); }

void Sieve(int n = 1'000'000) {
	for (int i = 2; i <= n; i++) {
		if (SP[i]) continue;
		for (int j = i; j <= n; j += i) {
			if (SP[j]) continue;
			SP[j] = i;
			E[j] = SP[j / i] == i ? E[j / i] + 1 : 1;
		}
	}
	Sum[1] = Sigma[1] = 1;
	for (int i = 2; i <= n; i++) {
		Sigma[i] = Sigma[i / Pow(SP[i], E[i])] * GetSigma(SP[i], E[i]);
		Sum[i] = Sum[i - 1] + Sigma[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Sieve();
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << Sum[n] << '\n';
	}
}
