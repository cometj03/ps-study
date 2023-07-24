#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, ans = 0;
	cin >> N;
	while (N--) {
		char ch;
		cin >> ch;
		ans += ch == '1';
	}
	cout << ans;
}