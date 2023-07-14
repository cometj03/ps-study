#include <iostream>
using namespace std;
#define endl "\n"
#define N 1010101
long long A[N];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T, a;
	for (int i = 1; i < N; i++) {
		for (int j = 1; i * j < N; j++) {
			A[i * j] += i;
		}
		A[i] += A[i - 1];
	}

	cin >> T;
	while (T--) {
		cin >> a;
		cout << A[a] << endl;
	}
	return 0;
}