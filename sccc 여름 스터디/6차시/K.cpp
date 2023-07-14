#include <bits/stdc++.h>
using namespace std;
int D[1010][1010];
string S[1010][1010];

int main() {
	string a, b;
	cin >> a >> b;
	int aLen = a.length(), bLen = b.length();
	a = "#" + a;  // index 1부터 시작
	b = "#" + b;
	for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			if (a[i] == b[j]) {
				D[i][j] = D[i - 1][j - 1] + 1;
				S[i][j] = S[i - 1][j - 1] + a[i];
			} else if (D[i][j] < D[i - 1][j]) {
				D[i][j] = D[i - 1][j];
				S[i][j] = S[i - 1][j];
			} else {
				D[i][j] = D[i][j - 1];
				S[i][j] = S[i][j - 1];
			}
		}
	}
	cout << D[aLen][bLen] << '\n' << S[aLen][bLen];
}