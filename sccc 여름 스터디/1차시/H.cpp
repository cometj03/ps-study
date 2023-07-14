#include <algorithm>
#include <iostream>
using namespace std;
#define endl "\n"
#define nbsp " "

int A[1010];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);

	int canExpress = 0;
	for (int i = 1; i <= N; i++) {
		if (canExpress < A[i] - 1) break;
		canExpress += A[i];
	}
	cout << canExpress + 1;
}