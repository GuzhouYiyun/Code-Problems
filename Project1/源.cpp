#include "bits_stdc++.h"
using namespace std;

int n;
vector<int> ans;
vector<bool> zt;

void change(int x) {
	if (x == 0) {
		ans.push_back(1);
		zt[0] = !zt[0];
		return;
	}
	if (x == 1) {
		if (!zt[0]) {
			change(0);
		}
		ans.push_back(2);
		zt[1] = !zt[1];
		return;
	}
	if (zt[x - 1] != 1) {
		change(x - 1);
	}
	for (int i = x - 2; i >= 0; --i) {
		if (zt[i] != 0) {
			change(i);
		}
	}
	zt[x] = !zt[x];
	ans.push_back(x + 1);
	return;
}

int main(void) {
	
	cout << "输入环数：";
	cin >> n;
	zt.assign(n, 0);
	cout << "输入各环状态(0下1上, 空格分开)：";
	for (int i = n - 1; i >= 0; --i) {
		bool t;
		cin >> t;
		zt[i] = t;
	}

	int k;
	cout << "输入目标全上(1)还是全下(0): ";
	cin >> k;

	for (int i = n - 1; i >= 0; --i) {
		if (zt[i] != k) {
			change(i);
		}
	}

	int temp = 0;
	for (auto x : ans) {
		cout << x;
		++temp;
		if (temp == 8) {
			cout << endl;
			temp = 0;
		}
	}

	return 0;
}