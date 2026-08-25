#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
int main(void) {

	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	
	map<pair<ll, ll>, bool> cant = { {{x, y}, true}, { { x - 1, y - 2 }, true }, {{x - 2, y - 1}, true}, {{x - 2, y + 1}, true}, {{x - 1, y + 2}, true}, {{x + 1, y + 2}, true}, {{x + 2, y + 1}, true}, {{x + 2, y - 1}, true}, {{x + 1, y - 2}, true} };
	vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, 0));
	dp[0][0] = 1;

	for (ll i = 0; i <= a; ++i) {
		for (ll j = 0; j <= b; ++j) {
			if (cant[{i, j}]) {
				continue;
			}
			else {
				if (i) {
					dp[i][j] += dp[i - 1][j];
				}
				if (j) {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}
	}

	cout << dp[a][b];

	return 0;
}