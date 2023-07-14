#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll A[100];

int main() {
	int N;
	cin >> N;
	A[1] = A[2] = 1;
	for (int i = 3; i <= N; i++) A[i] = A[i - 1] + A[i - 2];
	cout << A[N];
}