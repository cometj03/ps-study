#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int M, N, F[101010];
ll sum;

int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) cin >> F[i], sum += F[i];
	sort(F + 1, F + N + 1, greater<>());
}