#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> Q;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		Q.push(t);
		if (Q.size() >= i / 2) Q.pop();
		cout << Q.top() << '\n';
	}
}