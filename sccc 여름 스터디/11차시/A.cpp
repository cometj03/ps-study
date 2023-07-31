#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	set<int> s;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		if (s.find(a) != s.end()) s.erase(a);
	}
	cout << s.size() << '\n';
	for (auto it : s) cout << it << ' ';
}