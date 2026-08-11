#include "bits_stdc++.h"
using namespace std;
typedef long long unsigned int ll;
int main(void) {

	ll K;
	cin >> K;

	vector<ll> num(1, K);
	while (true) {
		ll up = num.size();
		if (num[up - 1] < up) {
			break;
		}
		num.push_back(num[up - 1] - num[up - 1] % up);
		num[up - 1] %= up;
	}

	for (ll i = 0; i < num.size(); ++i) {
		if (num[i] == 0) {
			continue;
		}
		else {
			cout << i << ' ' << num[i] << endl;
		}
	}

	return 0;
}