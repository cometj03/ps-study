#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, int> m;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		m[t]++;
	}

	int flag = 0;
	for (auto [k, v] : m) {
		if (k == 0) flag = -1;
		if (k == v) flag = k;
	}
	cout << flag;
}