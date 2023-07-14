#include <iostream>
using namespace std;
using ll = long long;

// L[N] : 레벨-N 버거의 길이
// P[N] : 레벨-N 버거의 전체 패티 개수
ll L[51], P[51];

ll Patty(int n, ll x) {
	if (n == 0 && x > 0) return 1;
	if (x >= L[n]) return P[n];
	if (x > L[n] / 2) return Patty(n - 1, L[n - 1]) + Patty(n - 1, x - L[n - 1] - 2) + 1;
	if (x > 1) return Patty(n - 1, x - 1);
	return 0;
}

int main() {
	P[0] = L[0] = 1;
	for (int i = 1; i <= 50; i++) {
		L[i] = 3 + 2 * L[i - 1];
		P[i] = 1 + 2 * P[i - 1];
	}
	int N;
	ll X;
	cin >> N >> X;
	cout << Patty(N, X);
}