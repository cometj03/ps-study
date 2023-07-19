#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, priority_queue<int>> m;
	m[1].push(0);
	cout << m[1].size() << '\n';
	m[1].push(1);
	cout << m[1].size() << '\n';
}