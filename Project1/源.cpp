#include "bits_stdc++.h"
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {

	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	int ans = num[0];
	for (int i = 0; i < n; ++i) {
		if (num[i] != 0) {
			ans = gcd(ans, abs(num[i]));
		}
	}

	cout << ans;

	return 0;
}