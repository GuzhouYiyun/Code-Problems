#include "bits_stdc++.h"
using namespace std;
typedef long long ll;

int main(void) {

	ll N;
	cin >> N;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	vector<int> temp(N, 0);
	temp[1] = 0;
	vector<int> prime;
	vector<bool> isprime(N, true);
	isprime[1] = false;
	for (int i = 2; i < N; ++i) {
		if (isprime[i]) {
			prime.push_back(i);
			temp[i] = i - 1;
		}
		for (auto x : prime) {
			if (x * i >= N) {
				break;
			}
			isprime[x * i] = false;
			if (i % x == 0) {
				temp[x * i] = temp[i] * x;
				break;
			}
			else {
				temp[x * i] = temp[i] * (x - 1);
			}
		}
	}

	ll ans = 0;
	for (ll i = 2; i < N; ++i) {
		ans += temp[i];
	}

	cout << ans * 2 + 3;

	return 0;
}