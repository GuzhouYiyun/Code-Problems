#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
#define MOD 998244353
int main(void) {

	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> num(n + 1);
	for (int i = 1; i <= n; ++i) {
		num[i] = s[i - 1] - '0';
	}

	if (n == 1) {
		if (k == 0) {
			cout << 1;
		}
		else {
			cout << 2;
		}
		return 0;
	}
	else if (n == 2) {
		if (k == 0) {
			cout << 1;
		}
		else if (k == 1) {
			cout << 3;
		}
		else {
			cout << 4;
		}
		return 0;
	}

	vector<vector<vector<vector<ll>>>> dp(2, vector<vector<vector<ll>>>(k + 1, vector<vector<ll>>(2, vector<ll>(2, 0))));
	//前几位 & 1，能改几个，末尾两位cd
	dp[2 & 1][0][num[1]][num[2]] = 1;
	if (k >= 1) {
		dp[2 & 1][1][!num[1]][num[2]] = 1;
		dp[2 & 1][1][num[1]][!num[2]] = 1;
	}
	if (k >= 2) {
		dp[2 & 1][2][!num[1]][!num[2]] = 1;
	}
	for (ll i = 3; i <= n; ++i) {

		for (ll j = 0; j < k + 1; ++j) {
			for (ll a = 0; a < 2; ++a) {
				for (ll b = 0; b < 2; ++b) {
					dp[i & 1][j][a][b] = 0;
				}
			}
		}

		for (ll j = 0; j <= k; ++j) {
			if (num[i] == 1) {
				//不翻
				dp[i & 1][j][0][1] = (dp[(i - 1) & 1][j][0][0] + dp[(i - 1) & 1][j][1][0]) % MOD;
				dp[i & 1][j][1][1] = (dp[(i - 1) & 1][j][0][1] + dp[(i - 1) & 1][j][1][1]) % MOD;
				//翻
				if (j >= 1) {
					dp[i & 1][j][0][0] = (dp[(i - 1) & 1][j - 1][0][0] + dp[(i - 1) & 1][j - 1][1][0]) % MOD;
					dp[i & 1][j][1][0] = dp[(i - 1) & 1][j - 1][0][1] % MOD;
				}
			}
			else {
				//不翻
				dp[i & 1][j][0][0] = (dp[(i - 1) & 1][j][0][0] + dp[(i - 1) & 1][j][1][0]) % MOD;
				dp[i & 1][j][1][0] = dp[(i - 1) & 1][j][0][1] % MOD;
				//翻
				if (j >= 1) {
					dp[i & 1][j][0][1] = (dp[(i - 1) & 1][j - 1][0][0] + dp[(i - 1) & 1][j - 1][1][0]) % MOD;
					dp[i & 1][j][1][1] = (dp[(i - 1) & 1][j - 1][0][1] + dp[(i - 1) & 1][j - 1][1][1]) % MOD;
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		for (ll a = 0; a <= 1; ++a) {
			for (ll b = 0; b <= 1; ++b) {
				ans = (ans + dp[n & 1][i][a][b]) % MOD;
			}
		}
	}

	cout << ans;

	return 0;
}