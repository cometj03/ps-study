#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int S = 0, M;
	cin >> M;
	while (M--) {
		string op;
		cin >> op;
		if (op == "all" || op == "empty") {
			S = (op == "all" ? -1 : 0);
			continue;
		}
		int x;
		cin >> x;
		int mask = 1 << (x - 1);
		if (op == "add") S |= mask;
		if (op == "remove") S &= ~mask;
		if (op == "check") cout << ((S & mask) != 0) << '\n';
		if (op == "toggle") S ^= mask;
	}
}