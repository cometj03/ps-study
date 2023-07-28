#include <bits/stdc++.h>
using namespace std;
int N, M, In[55];
double water[55];
vector<int> G[55];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		In[b]++;
	}
	water[1] = 100;
	queue<int> Q;
	for (int i = 1; i <= N; i++)
		if (In[i] == 0) Q.push(i);

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		if (G[v].empty()) continue;
		for (int w : G[v]) {
			if (--In[w] == 0) Q.push(w);
			water[w] += water[v] / G[v].size();
		}
		water[v] = 0;
	}

	double mx = 0;
	for (int i = 1; i <= N; i++) {
		cout << water[i] << ' ';
		mx = max(mx, water[i]);
	}
	printf("%.20lf", mx);
}