#include <bits/stdc++.h>
using namespace std;
int N, M, A[1010][1010], cnt;
bool C[1010];

void dfs(int n) {
	C[n] = true;
	for (int i = 1; i <= N; i++)
		if (A[n][i] && !C[i]) dfs(i);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		A[a][b] = A[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!C[i]) dfs(i), cnt++;
	}
	cout << cnt;
}