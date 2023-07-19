#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, P, total = 0;
	cin >> N >> P;
	map<int, priority_queue<int>> line;
	while (N--) {
		int num, p, cnt = 0;
		cin >> num >> p;
		priority_queue<int>& l = line[num];
		while (!l.empty() && l.top() > p) cnt++, l.pop();

		if (l.empty() || l.top() != p) {
			l.push(p);
			cnt++;
		}
		total += cnt;
	}
	cout << total;
}