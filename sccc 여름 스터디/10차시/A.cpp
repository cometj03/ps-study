#include <bits/stdc++.h>
using namespace std;
int N, M, In[32020];
vector<int> A[32020];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i < M; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		In[b]++;
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
		if (In[i] == 0) Q.push(i);
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		cout << v << ' ';
		for (auto it : A[v])
			if (--In[it] == 0) Q.push(it);
	}
}