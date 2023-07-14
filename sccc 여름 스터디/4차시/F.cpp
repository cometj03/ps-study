#include <iostream>
using namespace std;
using ll = long long;

int N, M, A[1010101];

ll f(ll t) {
	ll res = 0;
	for (int i = 1; i <= N; i++) res += t / A[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];

	ll l = 0, h = 1e12;
	while (l < h) {
		ll mid = (l + h) / 2;
		if (f(mid) >= M)
			h = mid;
		else
			l = mid + 1;
	}
	cout << h;
}