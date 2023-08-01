#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int S[202020], N, K;
ll ans;
map<int, ll> m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	int t;
	for (int i = 1; i <= N; i++) cin >> t, S[i] = S[i - 1] + t;
	for (int i = 0; i <= N; i++) {
		ans += m[S[i] - K];	 // 0 ~ i - 1 중에서 S[i] - K의 개수를 더해줌
		m[S[i]]++;
	}
	cout << ans;
}