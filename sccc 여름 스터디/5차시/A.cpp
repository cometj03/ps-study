#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int A[202020];

int gcd(int a, int b) {
	if (b == 0) return a;
	if (a < b) return gcd(b, a);
	return gcd(b, a % b);
}

int ggcd(int s, int e) {
	int g = A[s];
	for (int i = s + 1; i <= e; i++) g = gcd(g, A[i]);
	return g;
}

ll sol(int s, int e) {
	if (s == e) return A[s];
	int m = (s + e - 1) / 2;
	ll l = ggcd(s, m) + sol(m + 1, e);
	ll r = sol(s, m) + ggcd(m + 1, e);
	return max(l, r);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << sol(1, N);
}