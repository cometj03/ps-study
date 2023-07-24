#include <bits/stdc++.h>
using namespace std;

int P[1010], N;

int main() {
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
	sort(P, P + N);
	for (int i = 0; i < N; i++) sum += P[i] * (N - i);
	cout << sum;
}