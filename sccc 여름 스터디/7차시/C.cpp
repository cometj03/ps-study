#include <bits/stdc++.h>
using namespace std;
int A[1010101], B[1010101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	stack<int> s;
	for (int i = N; i >= 1; i--) {
		while (!s.empty() && s.top() <= A[i]) s.pop();
		B[i] = s.empty() ? -1 : s.top();
		s.push(A[i]);
	}
	for (int i = 1; i <= N; i++) cout << B[i] << ' ';
}