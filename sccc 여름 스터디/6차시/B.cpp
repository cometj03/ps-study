#include <bits/stdc++.h>
using namespace std;
int A[1010101];

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		A[i] = A[i - 1] + 1;
		if (i % 2 == 0) A[i] = min(A[i], A[i / 2] + 1);
		if (i % 3 == 0) A[i] = min(A[i], A[i / 3] + 1);
	}
	cout << A[N];
}