#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, k;

// num이 몇 번째인지 리턴
// 중복되는 숫자 있으면 가장 마지막 숫자의 자리

// N == 3이면
// 1 2 3
// 2 4 6
// 3 6 9
// 에서 각 행마다 num보다 작은 숫자가 몇 개 있는지 더함
ll f(ll num) {
	ll res = 0;
	for (int i = 1; i <= N; i++) {
		res += min((ll)N, num / i);
	}
	return res;
}

int main() {
	cin >> N >> k;
	ll l = 1, r = k;
	while (l < r) {
		ll m = (l + r) / 2;
		if (f(m) < k)
			l = m + 1;
		else
			r = m;
	}
	cout << l;
}