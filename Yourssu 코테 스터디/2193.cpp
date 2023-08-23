#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
ll B[101][2];  // B[i][j]: 길이가 i인 j로 시작하는 이친수의 개수

int main() {
	cin >> N;
	B[1][1] = B[1][0] = 1;
	for (int i = 2; i <= N; i++) {
		B[i][0] = B[i - 1][0] + B[i - 1][1];
		B[i][1] = B[i - 1][0];
	}
	cout << B[N][1];
}