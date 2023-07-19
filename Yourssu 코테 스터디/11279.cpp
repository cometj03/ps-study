#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<int> pq;
	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
			continue;
		}
		pq.push(a);
	}
}