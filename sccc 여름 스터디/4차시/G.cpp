#include <iostream>
using namespace std;
using ull = unsigned long long;

int main() {
	ull n, r = (1LL << 32) - 1, l = 0;
	cin >> n;
	while (l < r) {
		ull m = (l + r) / 2;
		if (m * m >= n)
			r = m;
		else
			l = m + 1;
	}
	cout << l;
}