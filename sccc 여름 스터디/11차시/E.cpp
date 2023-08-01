#include <bits/stdc++.h>
using namespace std;

void Solve() {
	int N, A[10101] = {0};
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << (N + 1) / 2 << '\n';
	priority_queue<int, vector<int>, less<>> LQ;	 // 중앙값보다 왼쪽 값 관리
	priority_queue<int, vector<int>, greater<>> RQ;	 // 오른쪽 값 관리

	int center = A[1];
	cout << center << ' ';
	for (int i = 1; i <= N / 2; i++) {
		for (int k = 0; k < 2; k++) {
			int idx = 2 * i + k;
			if (A[idx] > center)
				RQ.push(A[idx]);
			else
				LQ.push(A[idx]);
		}

		if (LQ.size() > RQ.size())
			RQ.push(center), center = LQ.top(), LQ.pop();
		else if (LQ.size() < RQ.size())
			LQ.push(center), center = RQ.top(), RQ.pop();
		cout << center << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) Solve();
}