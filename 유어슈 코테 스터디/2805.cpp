#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int A[1010101], N, M;

ll f(int x) {
	ll res = 0;
	for (int i = 1; i <= N; i++)
		if (A[i] > x) res += A[i] - x;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int longest = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		longest = max(longest, A[i]);
	}
	int low = 0, high = longest;
	while (low < high - 1) {
		int mid = (low + high) / 2;
		if (f(mid) >= M)
			low = mid;
		else
			high = mid;
	}
	cout << low;
}