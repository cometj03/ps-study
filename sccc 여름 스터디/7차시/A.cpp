#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	deque<int> q;
	int N;
	cin >> N;
	while (N--) {
		string op;
		cin >> op;
		if (op == "push_front") {
			int n;
			cin >> n;
			q.push_front(n);
		}
		if (op == "push_back") {
			int n;
			cin >> n;
			q.push_back(n);
		}
		if (op == "pop_front") {
			cout << (q.empty() ? -1 : q.front()) << '\n';
			if (!q.empty()) q.pop_front();
		}
		if (op == "pop_back") {
			cout << (q.empty() ? -1 : q.back()) << '\n';
			if (!q.empty()) q.pop_back();
		}
		if (op == "size") cout << q.size() << '\n';
		if (op == "empty") cout << q.empty() << '\n';
		if (op == "front") cout << (q.empty() ? -1 : q.front()) << '\n';
		if (op == "back") cout << (q.empty() ? -1 : q.back()) << '\n';
	}
}