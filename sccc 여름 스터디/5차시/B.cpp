#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int A[1010101];

ll Merge(int s, int m, int e) {
	static int tmp[1010101];
	ll res = 0, cnt = 0;
	int idxL = s, idxR = m + 1, i = s;
	while (idxL <= m && idxR <= e) {
		if (A[idxL] < A[idxR]) {
			tmp[i] = A[idxL++];
			res += cnt;
		} else {
			tmp[i] = A[idxR++];
			cnt++;
		}
		i++;
	}
	for (int k = idxL; k <= m; k++, i++) {
		tmp[i] = A[k];
		res += cnt;
	}
	for (int k = idxR; k <= e; k++, i++) {
		tmp[i] = A[k];
		cnt++;
	}
	for (int k = s; k <= e; k++) A[k] = tmp[k];
	return res;
}

ll MergeSort(int s, int e) {
	if (s == e) return 0;
	int m = (s + e) / 2;
	ll a = MergeSort(s, m);
	ll b = MergeSort(m + 1, e);
	ll c = Merge(s, m, e);
	return a + b + c;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << MergeSort(1, N) << '\n';
	for (int i = 1; i <= N; i++) cout << A[i];
}