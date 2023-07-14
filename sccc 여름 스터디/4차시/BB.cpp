#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[1010][1010], N;

ll f(int x) {
	ll res = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) res += min(x, A[i][j]);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	ll sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) cin >> A[i][j], sum += A[i][j];
	sum >>= 1;
	int l = 0, r = 1e9;
	while (l < r) {
		int m = (l + r) / 2;
		if (f(m) >= sum)
			r = m;
		else
			l = m + 1;
	}
	cout << l;
}