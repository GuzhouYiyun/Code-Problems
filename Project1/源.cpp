#include "bits_stdc++.h"
using namespace std;
int main(void) {

	string a, b;
	cin >> a >> b;

	vector<int> A, B;
	for (int i = a.size() - 1; i >= 0; --i) {
		A.push_back(a[i] - '0');
	}
	for (int i = b.size() - 1; i >= 0; --i) {
		B.push_back(b[i] - '0');
	}

	vector<int> ans;
	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			int now = A[j] * B[i];
			if (ans.size() < i + j + 1) {
				ans.push_back(now % 10);
				ans.push_back(now / 10);
			}
			else if (ans.size() == i + j + 1) {
				ans[i + j] += now % 10;
				ans.push_back(now / 10);
			}
			else {
				ans[i + j] += now % 10;
				ans[i + j + 1] += now / 10;
			}
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] >= 10) {
			if (ans.size() == i + 1) {
				ans.push_back(ans[i] / 10);
			}
			else {
				ans[i + 1] += ans[i] / 10;
			}
			ans[i] %= 10;
		}
	}

	bool beg = false, zero = true;
	for (int i = ans.size() - 1; i >= 0; --i) {
		if (beg) {
			cout << ans[i];
		}
		else if (ans[i] != 0) {
			cout << ans[i];
			beg = true;
		}
		if (ans[i] != 0) {
			zero = false;
		}
	}
	if (zero) {
		cout << 0;
	}

	return 0;
}