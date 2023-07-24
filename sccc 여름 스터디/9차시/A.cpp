#include <bits/stdc++.h>
using namespace std;
int C[11], N, K;

int main() {
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> C[i];
	sort(C, C + N, greater<int>());
	for (int i = 0; i < N; i++) {
		cnt += K / C[i];
		K %= C[i];
	}
	cout << cnt;
}