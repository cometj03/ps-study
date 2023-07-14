#include <iostream>
using namespace std;
using ll = long long;

int A[1010], B[1010];
const int mod = 1'000'000'000;

int gcd(int a, int b) {
	if (b == 0) return a;
	if (a < b) return gcd(b, a);
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	ll totalGCD = 1;
	bool exceed = false;

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> B[i];
		for (int j = 1; j <= N; j++) {
			int g = gcd(A[j], B[i]);
			A[j] /= g;
			B[i] /= g;
			totalGCD *= g;
			if (totalGCD >= mod) {
				totalGCD %= mod;
				exceed = true;
			}
		}
	}
	if (exceed)
		printf("%09lld\n", totalGCD);
	else
		printf("%lld\n", totalGCD);
}
