#include <bits/stdc++.h>
using namespace std;
int P[202], A[1010], N, M;

void Init() {
	for (int i = 1; i <= N; i++) P[i] = i;
}
int Find(int v) {
	if (v == P[v]) return v;
	return P[v] = Find(P[v]);
}
void Union(int u, int v) {
	int u_root = Find(u), v_root = Find(v);
	if (u_root != v_root) P[v_root] = u_root;
}

bool Check() {
	int prev_root = Find(A[1]);
	for (int i = 2; i <= M; i++)
		if (prev_root != Find(A[i])) return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	Init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int t;
			cin >> t;
			if (t) Union(i, j);
		}
	}
	for (int i = 1; i <= M; i++) cin >> A[i];
	cout << (Check() ? "YES" : "NO");
}