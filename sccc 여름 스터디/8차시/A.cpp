#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 20; i++) {
		if (N & (1 << i)) cout << i << ' ';
	}
}