#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	set<string, greater<string>> s;
	while (N--) {
		string name, op;
		cin >> name >> op;
		if (op == "enter")
			s.insert(name);
		else
			s.erase(name);
	}
	for (auto& name : s) cout << name << '\n';
}