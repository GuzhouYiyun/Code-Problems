#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
int main(void) {

	vector<vector<ll>> same = {
		{ 0, -3, -4, -2, -1},
		{-3,  5, -1, -2, -1},
		{-4, -1,  5, -3, -2},
		{-2, -2, -3,  5, -2},
		{-1, -1, -2, -2,  5} };
	map<char, ll> f = { {'0', 0}, {'A', 1}, {'C', 2}, {'G', 3}, {'T', 4} };

	ll a;
	cin >> a;
	vector<ll> sa(a + 1, 0);
	for (ll i = 1; i <= a; ++i) {
		char c;
		cin >> c;
		sa[i] = f[c];
	}
	ll b;
	cin >> b;
	vector<char> sb(b + 1, 0);
	for (ll i = 1; i <= b; ++i) {
		char c;
		cin >> c;
		sb[i] = f[c];
	}

	//a的，b的
	vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, -1e18));

	dp[0][0] = 0;
	for (ll i = 1; i <= a; ++i) {
		dp[i][0] = same[sa[i]][0] + dp[i - 1][0];
	}
	for (ll i = 1; i <= b; ++i) {
		dp[0][i] = same[0][sb[i]] + dp[0][i - 1];
	}

	for (ll i = 1; i <= a; ++i) {
		for (ll j = 1; j <= b; ++j) {
			dp[i][j] = max({ dp[i - 1][j] + same[sa[i]][0], dp[i][j - 1] + same[0][sb[j]], dp[i - 1][j - 1] + same[sa[i]][sb[j]] });
		}
	}

	cout << dp[a][b];

	return 0;
}