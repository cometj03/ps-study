#include <iostream>
using namespace std;
#define endl "\n"
#define nbsp " "

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n, l, fast = 0, late = 0;
		cin >> l >> n;
		for (int i = 0; i < n; i++) {
			int pos;
			cin >> pos;
			late = max(late, max(pos, l - pos));
			fast = max(fast, min(pos, l - pos));
		}
		cout << fast << nbsp << late << endl;
	}
}