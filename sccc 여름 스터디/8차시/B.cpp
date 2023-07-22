#include <bits/stdc++.h>
using namespace std;
int A[22], N, S;

int main() {
	int ans = 0;
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int bit = 1; bit < (1 << N); bit++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (bit & (1 << j)) sum += A[j];
		}
		if (sum == S) ans++;
	}
	cout << ans;
}