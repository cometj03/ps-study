#include <bits/stdc++.h>
using namespace std;
int A[10101], N;
// D[v][0] : 루트노드 v를 포함하지 않은 상태에서의 최댓값
// D[v][1] : v를 포함한 상태에서의 최대값
int D[10101][2];
vector<int> G[10101];

void dfs(int v, int b = -1) {
	for (auto w : G[v]) {
		if (w == b) continue;
		dfs(w, v);
		// v를 선택하지 않았을 때 자식의 선택 여부는 상관 없음
		D[v][0] += max(D[w][0], D[w][1]);
		// v를 선택했을 때 자식은 선택하지 않아야 함
		D[v][1] += D[w][0];
	}
	D[v][1] += A[v];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1);
	cout << max(D[1][0], D[1][1]);
}