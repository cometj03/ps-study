#include <bits/stdc++.h>
using namespace std;
// 음.. 메모리초과
int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<stack<int>> saved;
	stack<int> list;
	int N;
	cin >> N;
	while (N--) {
		saved.push_back(list);
		char op;
		cin >> op;
		if (op == 'a') {
			int n;
			cin >> n;
			list.push(n);
			cout << n << '\n';
		}
		if (op == 't') {
			int n;
			cin >> n;
			list = saved[n - 1];
			cout << (list.empty() ? -1 : list.top()) << '\n';
		}
		if (op == 's') {
			if (list.empty())
				cout << -1 << '\n';
			else {
				list.pop();
				cout << (list.empty() ? -1 : list.top()) << '\n';
			}
		}
	}
}