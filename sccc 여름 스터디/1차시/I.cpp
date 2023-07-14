#include <iostream>
using namespace std;
#define endl "\n"
#define nbsp " "

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i < N / 2 + 1; i++) {
		cout << N - i + 1 << nbsp;
		cout << i << nbsp;
	}
	if (N % 2 == 1) cout << N / 2 + 1;
}