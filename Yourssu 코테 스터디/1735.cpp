#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int p = a * d + b * c, q = b * d;
	int g = __gcd(p, q);
	cout << p / g << ' ' << q / g;
}