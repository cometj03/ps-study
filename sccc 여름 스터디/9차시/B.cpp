#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M, S, R;	// S: 부피의 합, R: 설탕의 합

int main() {
	cin >> N >> M;
	vector<pair<ll, ll>> v(N);	// pair<volume, sugar>
	for (auto& i : v) cin >> i.first >> i.second;
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.second * b.first > b.second * a.first;
	});	 // 비율 순으로 정렬

	for (auto drink : v) {
		if (S + drink.first <= M) {
			S += drink.first;
			R += drink.second;
		} else {
			ll add = M - S;
			ll p = R * drink.first + add * drink.second, q = drink.first;
			ll g = __gcd(p, q);
			cout << p / g << "/" << q / g;
			return 0;
		}
	}
	cout << R << "/1";
}