#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool C[10101];						   // 정점 체크
ll N, a, b, c, d, X[10101], D[10101];  // D[i] : i번 정점을 MST에 추가하기 위한 비용

ll dist(int i, int j) {
	if (i > j) return dist(j, i);
	return (((__int128)X[i] * a + (__int128)X[j] * b) % c) ^ d;	 // 곱셈 오버플로우
}

ll Prim() {
	ll res = 0;
	for (int i = 0; i < N; i++) D[i] = 1e14;
	D[0] = 0;
	for (int _ = 0; _ < N; _++) {
		int v = -1;
		for (int i = 0; i < N; i++) {
			if (C[i]) continue;
			if (v == -1 || D[v] > D[i]) v = i;
		}
		C[v] = true;
		res += D[v];
		for (int i = 0; i < N; i++)
			if (!C[i]) D[i] = min(D[i], dist(v, i));
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> a >> b >> c >> d;
	for (int i = 0; i < N; i++) cin >> X[i];
	cout << Prim();
}