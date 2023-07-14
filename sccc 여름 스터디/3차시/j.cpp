#include <iostream>
using namespace std;
using ll = long long;
#define endl '\n'

int T[101010];

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i <= N - 2; i++) cin >> T[i];

	int lcm = T[1];
	for (int i = 2; i <= N - 2; i++) {
		int g = gcd(lcm, T[i]);
		lcm = lcm / g * T[i];
	}
	cout << lcm;
}
