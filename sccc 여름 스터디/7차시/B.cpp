#include <bits/stdc++.h>
using namespace std;

bool VPS(string& s) {
	stack<int> st;
	for (char c : s) {
		if (c == '(')
			st.push(1);
		else {
			if (st.empty()) return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		string input;
		cin >> input;
		cout << (VPS(input) ? "YES" : "NO") << '\n';
	}
}