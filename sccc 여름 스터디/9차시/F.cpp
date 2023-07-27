#include <bits/stdc++.h>
using namespace std;
const int mod = 4e4;
int N;

int main() {
	cin >> N;
	vector<pair<int, int>> v(N);
	for (auto& i : v) cin >> i.first >> i.second;
	sort(v.begin(), v.end(), [](auto a, auto b) {
		auto [a1, b1] = a;
		auto [a2, b2] = b;
		if (a1 == 0) return false;
		if (a2 == 0) return true;
		if (b1 == 0 && b2 == 0) return a1 < a2;
		return a2 * b1 < a1 * b2;
	});

	long long T = 0;
	for (auto& i : v) {
		T = (T * (i.first + 1) + i.second) % mod;
	}
	cout << T;
}