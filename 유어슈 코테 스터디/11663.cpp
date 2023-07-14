#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
	while (M--) {
		int a, b;
		cin >> a >> b;
		auto ai = lower_bound(v.begin(), v.end(), a);
		auto bi = upper_bound(v.begin(), v.end(), b);
		cout << bi - ai << endl;
	}
}