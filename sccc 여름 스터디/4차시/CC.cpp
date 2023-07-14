#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, C, A[202020];

// 최소 interval 만큼 간격 있을 때 놓을 수 있는 공유기 개수의 최대
ll f(ll interval) {
	ll cnt = 1;
	int pos = A[1], i = 2;
	while (i <= N) {
		if (A[i] >= pos + interval) {
			cnt++;
			pos = A[i];
		}
		i++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);
	ll l = 1, r = A[N];
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (f(mid) >= C)
			l = mid;
		else
			r = mid - 1;
	}
	cout << r;
}