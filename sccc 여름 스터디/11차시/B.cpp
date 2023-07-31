#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<string, int> m;
	vector<string> v;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		if (s.length() >= M && !m[s]++) v.push_back(s);
	}
	sort(v.begin(), v.end(), [&m](const string& a, const string& b) {
		if (m[a] != m[b]) return m[a] > m[b];
		if (a.length() != b.length()) return a.length() > b.length();
		return a < b;
	});
	for (auto it : v) cout << it << '\n';
}