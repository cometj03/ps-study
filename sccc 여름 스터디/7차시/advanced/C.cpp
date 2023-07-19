#include <bits/stdc++.h>
using namespace std;
vector<string> sol;
vector<pair<int, int>> v;

string delete_all_white_space(string& s) {
	string result = s;
	string::size_type pos = 0;
	while ((pos = result.find(" ")) != string::npos) {
		result.replace(pos, 1, "");
	}
	return result;
}

void solve(string s, int i, bool full) {
	if (i >= v.size()) {
		if (!full) sol.push_back(s);
		return;
	}
	const pair<int, int> idx = v[i];
	s.replace(idx.first, 1, " ");
	s.replace(idx.second, 1, " ");
	solve(s, i + 1, false);
	s.replace(idx.first, 1, "(");
	s.replace(idx.second, 1, ")");
	solve(s, i + 1, full);
}

int main() {
	string exp;
	stack<int> s;
	cin >> exp;
	int len = exp.length();
	for (int i = 0; i < len; i++) {
		if (exp[i] == '(') {
			s.push(i);
		} else if (exp[i] == ')') {
			v.push_back(make_pair(s.top(), i));
			s.pop();
		}
	}
	solve(exp, 0, true);

	set<string> ans;
	for (auto& s : sol) {  // 모든 공백문자 삭제
		ans.insert(delete_all_white_space(s));
	}
	for (auto& s : ans) cout << s << '\n';
}