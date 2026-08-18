#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
int main(void) {

	ll N, B;
	cin >> N >> B;

	vector<ll> P(N), S(N);
	for (ll i = 0; i < N; ++i) {
		cin >> P[i] >> S[i];
	}

	vector<vector<ll>> dp(N + 1, vector<ll>(2, 1e18));
	dp[0][0] = 0;
	for (ll i = 0; i < N; ++i) {
		ll use = P[i] / 2 + S[i], unuse = P[i] + S[i];
		for (ll j = N; j; --j) {
			dp[j][0] = min(dp[j - 1][0] + unuse, dp[j][0]);
			dp[j][1] = min(min(dp[j - 1][0] + use, dp[j - 1][1] + unuse), dp[j][1]);
		}
	}

	for (ll i = N; i >= 0; --i) {
		if (dp[i][0] <= B or dp[i][1] <= B) {
			cout << i;
			break;
		}
	}

	return 0;
}