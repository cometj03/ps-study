#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll sum = 0;
	int N, cnt = 0;
	cin >> N;
	for (int i = 1, j = 1; i <= N; sum -= i++) {
		while (j <= N && sum < N) sum += j++;
		if (sum == N) cnt++;
	}
	cout << cnt;
}