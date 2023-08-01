#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<>> Q;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N * N; i++) {
		int t;
		cin >> t;
		Q.push(t);
		if (Q.size() > N) Q.pop();
	}
	cout << Q.top();
}