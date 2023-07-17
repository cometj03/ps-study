#include <bits/stdc++.h>
using namespace std;
int A[10101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	queue<int> q;
	int N, M, sum = 0, cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		sum += A[i];
		q.push(A[i]);
		while (!q.empty() && sum > M) {
			sum -= q.front();
			q.pop();
		}
		if (sum == M) cnt++;
	}
	cout << cnt;
}