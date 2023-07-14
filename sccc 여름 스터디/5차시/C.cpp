#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int A[101010];

ll MinRect(int s, int e) {
	if (s > e) return 0;
	if (s == e) return A[s];
	int m = (s + e) / 2;
	ll res = A[m];
	int h = A[m], w = 1, i = m - 1, j = m + 1;
	//  A[m]을 포함하는 모든 경우 확인
	while (i >= s && j <= e) {
		// 둘 중 더 큰거 선택
		if (A[i] > A[j])
			h = min(h, A[i--]);
		else
			h = min(h, A[j++]);
		w++;
		res = max(res, (ll)h * w);
	}
	while (i >= s) {
		w++;
		h = min(h, A[i--]);
		res = max(res, (ll)h * w);
	}
	while (j <= e) {
		w++;
		h = min(h, A[j++]);
		res = max(res, (ll)h * w);
	}
	// A[m]을 제외한 범위([s, m-1]과 [m+1, e])도 생각
	res = max(res, MinRect(s, m - 1));
	res = max(res, MinRect(m + 1, e));
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << MinRect(1, N);
}