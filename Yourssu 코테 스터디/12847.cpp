#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int A[101010], N, M;
ll total, mx;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) total += A[i];
	for (int i = 1; i <= N - M + 1; total += A[i + M] - A[i++]) mx = max(mx, total);
	cout << mx;
}