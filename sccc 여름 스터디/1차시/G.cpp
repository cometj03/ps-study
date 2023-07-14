#include <iostream>
using namespace std;
#define endl "\n"
#define nbsp " "

long long P[1010][1010], sum[1010], dis;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			cin >> P[j][i];
			sum[i] += P[j][i];
		}
	}
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			dis += abs(P[j][i] - sum[i] / M);
		}
	}
	cout << dis << endl;
	for (int i = 1; i <= N; i++) cout << sum[i] / M << nbsp;
}