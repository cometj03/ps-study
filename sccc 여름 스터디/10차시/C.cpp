#include <bits/stdc++.h>
using namespace std;
int N, M, P[1010], In[1010];
vector<int> G[1010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		In[b]++;
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (In[i] == 0) {
			Q.push(i);
			P[i] = 1;
		}
	}
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (auto w : G[v]) {
			if (--In[w] == 0) Q.push(w), P[w] = P[v] + 1;
		}
	}

	for (int i = 1; i <= N; i++) cout << P[i] << ' ';
}