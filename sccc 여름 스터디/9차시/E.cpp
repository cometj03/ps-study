#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<double, int>> A;  // pair<T / S, index>

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		double t, s;
		cin >> t >> s;
		A.emplace_back(t / s, i);
	}
	sort(A.begin(), A.end(), [](auto a, auto b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	});
	for (auto& i : A) cout << i.second << ' ';
}