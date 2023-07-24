#include <bits/stdc++.h>
using namespace std;
int N, cnt;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	vector<pair<int, int>> room(N);
	for (auto& r : room) cin >> r.first >> r.second;
	sort(room.begin(), room.end(), [](auto a, auto b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	int mx = room[0].second;
	for (int i = 1; i < N; i++) {
		if (room[i].first >= mx) {
			mx = room[i].second;
			cnt++;
		}
	}
	cout << cnt;
}