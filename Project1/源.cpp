#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
int main(void) {

	ll T;
	cin >> T;

	while (T--) {
		
		ll n;
		cin >> n;
		vector<ll> a(n + 1);
		for (ll i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sort(a.begin() + 1, a.end());

		//false -> 不可以凑
		vector<bool> dp(25001);
		dp[0] = true;
		ll ans = 0;
		for (ll i = 1; i <= n; ++i) {
			ll v = a[i];
			if (dp[v] == false) {
				++ans;
				for (ll x = v; x <= a.back(); ++x) {
					dp[x] = dp[x] or dp[x - v];
				}
			}
		}

		cout << ans << endl;

	}

	return 0;
}