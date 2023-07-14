#include <iostream>
#include <map>
using namespace std;
#define endl "\n"
#define nbsp " "

int n, k, A[1010101];

multimap<int, int> m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		char tmp;
		cin >> tmp;
		int num = (tmp == 'R' ? k : -1);
		A[i] = A[i - 1] + num;
		m.insert(pair<int, int>(A[i], i));
	}

	int maxLen = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (m.count(it->first) <= 1) continue;
		int a = m.lower_bound(it->first)->second;
		auto u = m.upper_bound(it->first);
		u--;
		int b = u->second;
		maxLen = max(maxLen, b - a);
	}
	cout << maxLen;
}