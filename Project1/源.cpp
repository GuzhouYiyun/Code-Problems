#include "bits_stdc++.h"
using namespace std;
typedef long long ll;
int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		if (n == 1) {
			int a;
			cin >> a;
			cout << 0 << endl;
			continue;
		}
		else if (n == 2) {
			int a, b;
			cin >> a >> b;
			int t = max(abs(a), abs(b));
			cout << max(t, abs(a - b)) << endl;
			continue;
		}

		vector<int> z, f;
		int zero = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;

			if (x > 0) {
				z.push_back(x);
			}
			else if (x < 0) {
				f.push_back(x);
			}
			else {
				++zero;
			}
		}

		sort(z.begin(), z.end(), [](const int& a, const int& b) {
			return a > b;
			});
		sort(f.begin(), f.end(), [](const int& a, const int& b) {
			return a < b;
			});

		ll ans;
		if (z.empty()) {
			if (zero) {
				f.push_back(0);
			}
			ll sum = accumulate(f.begin(), f.end(), 0LL);
			ans = 2LL * f.back() - sum - f.front();
		}
		else if (f.empty()) {
			if (zero) {
				z.push_back(0);
			}
			ll sum = accumulate(z.begin(), z.end(), 0LL);
			ans = sum + z.front() - 2LL * z.back();
		}
		else if (z.size() == 1 and f.size() == 1) {
			if (zero == 1) {
				ans = max(2LL * z.front() - f.front(), z.front() - 2LL * f.front());
			}
			else {
				ans = 2LL * z.front() - 2LL * f.front();
			}
		}
		else if (z.size() == 1) {
			ll sum = accumulate(f.begin(), f.end(), 0LL);
			if (zero) {
				ans = 2LL * z.front() - sum - f.front();
			}
			else {
				ll t;
				if (f.size() != 2) {
					t = 2LL * z.front() + 2LL * f.back() - sum - f.front();
				}
				else {
					t = 2LL * z.front() - f.front();
				}
				ans = max(z.front() - sum - f.front(), t);
			}
		}
		else if (f.size() == 1) {
			ll sum = accumulate(z.begin(), z.end(), 0LL);
			if (zero) {
				ans = sum + z.front() - 2LL * f.front();
			}
			else {
				ll t;
				if (z.size() != 2) {
					t = sum - 2LL * z.back() + z.front() - 2LL * f.front();
				}
				else {
					t = z.front() - 2 * f.front();
				}
				ans = max(sum + z.front() - f.front(), t);
			}
		}
		else {
			ans = accumulate(z.begin(), z.end(), (long long)z.front()) - accumulate(f.begin(), f.end(), (long long)f.front());
		}

		cout << ans << endl;
	}

	return 0;
}