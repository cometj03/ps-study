// 행성을 x축 오름차순으로 1 ~ N으로 번호를 매기면
// 1번 행성부터 N번 행성까지 가는, 중간 정점이 겹치지 않는 두 경로를 구하는 것과 같음

// 빗변 길이 함수 : hypot()
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

// D[i][j] = 왼발이 i, 오른발이 j에 있을 때 (N, N)까지 가는 데 필요한 최소 비용
double D[555][555];
int N;
vector<pair<int, int>> P;

double dist(int a, int b) { return hypot(P[a].x - P[b].x, P[a].y - P[b].y); }

// double f(int l, int r) {
// 	if (D[l][r] != -1) return D[l][r];
// 	if (l == N || r == N) {
// 		return D[l][r] = dist(min(l, r), N);
// 	}
// 	D[l][r] = min(f(l, l + 1) + dist(r, l + 1), f(r + 1, r) + dist(r + 1, r));
// 	return D[l][r];
// }

double f(int i, int j) {
	double& res = D[i][j];
	if (res >= 0) return res;
	if (i == N) return res = dist(j, N);
	if (j == N) return res = dist(i, N);
	int k = max(i, j) + 1;
	return res = min(f(k, j) + dist(i, k), f(i, k) + dist(j, k));
}

void Solve() {
	memset(D, -1, sizeof(D));
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		P.emplace_back(a, b);
	}
	// sort(P.begin(), P.end(), [](auto a, auto b) { return a.x < b.x; });
	printf("%.20lf\n", f(1, 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) Solve();
}