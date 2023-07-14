#include <bits/stdc++.h>
using namespace std;

int D[1010][1010];	// D[i][j]: A[1..i], B[1..j] 중 LCS의 최대값

int main() {
	string A, B;
	cin >> A >> B;
	A = "#" + A;
	B = "#" + B;
	int aLen = A.length(), bLen = B.length();
	for (int i = 1; i < aLen; i++) {
		for (int j = 1; j < bLen; j++) {
			if (A[i] == B[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
		}
	}
	cout << D[aLen - 1][bLen - 1];
}