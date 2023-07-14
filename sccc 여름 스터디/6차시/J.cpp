#include <bits/stdc++.h>
using namespace std;
int A[1010], D[1010], P[1010];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				P[i] = j;
			}
		}
	}
	int pos = 1;
	for (int i = 2; i <= N; i++)
		if (D[i] > D[pos]) pos = i;
	cout << D[pos] << '\n';

	vector<int> v;
	for (int i = pos; i > 0; i = P[i]) v.push_back(A[i]);
	reverse(v.begin(), v.end());
	for (int it : v) cout << it << ' ';
}