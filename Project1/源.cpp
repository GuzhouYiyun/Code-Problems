#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
int main(void) {

	ll N;
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 1e18));
	vector<ll> m(N + 1, 0);
	for (ll i = 1; i <= N; ++i) {
		cin >> m[i];
		m[i] += m[i - 1];
		dp[i][i] = 0;
	}

	for (ll len = 2; len <= N; ++len) {
		for (ll i = 1; i <= N; ++i) {
			ll j = i + len - 1;
			if (j > N) {
				continue;
			}
			for (ll k = i; k < j; ++k) {
				dp[i][j] = min(dp[i][k] + dp[k + 1][j] + m[j] - m[i - 1], dp[i][j]);
			}
		}
	}

	cout << dp[1][N];

	return 0;
}