#include <bits/stdc++.h>
using namespace std;
int N, M, A[1010101], B[1010101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];

	int i = 1, j = 1;
	while (i <= N && j <= M) {
		if (A[i] < B[j])
			cout << A[i++] << ' ';
		else
			cout << B[j++] << ' ';
	}
	while (i <= N) cout << A[i++] << ' ';
	while (j <= M) cout << B[j++] << ' ';
}