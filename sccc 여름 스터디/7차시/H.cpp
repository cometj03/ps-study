#include <bits/stdc++.h>
using namespace std;
int A[5050505];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, L;
	cin >> N >> L;
	for (int i = 1; i <= N; i++) cin >> A[i];
	deque<pair<int, int>> dq;  // <value, index>
	for (int i = 1; i <= N; i++) {
		while (!dq.empty() && dq.front().second < i - L + 1) dq.pop_front();
		while (!dq.empty() && dq.back().first >= A[i]) dq.pop_back();
		dq.push_back({A[i], i});
		cout << dq.front().first << ' ';
	}
}