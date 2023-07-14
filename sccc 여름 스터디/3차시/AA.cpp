#include <iostream>
using namespace std;

bool IsPelin(int n) {
	int p = 0, x = n;
	while (x) {
		p = 10 * p + x % 10;
		x /= 10;
	}
	return p == n;
}

bool IsPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	if (a % 2 == 0) a++;
	for (int i = a; i <= b; i += 2)
		if (IsPelin(i) && IsPrime(i)) cout << i << '\n';
	cout << -1;
}