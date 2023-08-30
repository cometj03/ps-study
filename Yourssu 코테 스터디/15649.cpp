#include <bits/stdc++.h>
using namespace std;
int N, M, A[10], Chosen[10];
void f(int choose) {
	if (choose == M) {
		for (int i = 0; i < M; i++) cout << A[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!Chosen[i]) {
			Chosen[i] = 1;
			A[choose] = i;
			f(choose + 1);
			Chosen[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	f(0);
}