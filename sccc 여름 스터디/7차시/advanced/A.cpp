#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	vector<char> v;
	cin >> p;
	int len = p.length(), cnt = 0;
	v.push_back('(');
	for (int i = 1; i < len; i++) {
		if (p[i] == '(')
			v.push_back(p[i]);
		else if (p[i - 1] == '(') {
			v.pop_back();
			cnt += v.size();
		} else
			v.pop_back(), cnt++;
	}
	cout << cnt;
}