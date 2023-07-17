#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// L[i]: A[i]의 왼쪽 중 A[i]보다 작은 것 중 가장 오른쪽에 있는 블록의 인덱스
// R[i]: L[i]와 방향 반대 (오른쪽)
int L[101010], R[101010], A[101010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	stack<int> s1, s2;
	for (int i = 1; i <= N; i++) {
		while (!s1.empty() && A[s1.top()] >= A[i]) s1.pop();
		L[i] = s1.empty() ? 0 : s1.top();
		s1.push(i);
	}
	for (int i = N; i >= 1; i--) {
		while (!s2.empty() && A[s2.top()] >= A[i]) s2.pop();
		R[i] = s2.empty() ? N + 1 : s2.top();
		s2.push(i);
	}
	int res = 0;
	for (int i = 1; i <= N; i++) res = max(res, A[i] * (R[i] - L[i] - 1));
	cout << res;
}