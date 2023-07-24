#include <bits/stdc++.h>
using namespace std;
int A[1010][1010], N, M, V;
bool C[1010];

void dfs(int n) {
	cout << n << ' ';
	C[n] = true;
	for (int i = 1; i <= N; i++)
		if (A[n][i] && !C[i]) dfs(i);
}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	C[n] = true;
	while (!q.empty()) {
		int m = q.front();
		q.pop();
		cout << m << ' ';
		for (int i = 1; i <= N; i++)
			if (A[m][i] && !C[i]) q.push(i), C[i] = true;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		A[a][b] = A[b][a] = 1;
	}
	dfs(V);
	for (int i = 1; i <= N; i++) C[i] = false;
	cout << '\n';
	bfs(V);
}