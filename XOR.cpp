#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

bool xorr(ll*arr, ll n) {
	if (n < 4) {
		return false;
	}

	for (ll i = 0; i < n - 3; ++i) {
		for (ll j = i + 1; j < n - 2; ++j) {
			for (ll k = j + 1; k < n - 1; k++) {
				for (ll l = k + 1; l < n; ++l)
					if ((arr[i]^arr[j]^arr[k]^arr[l]) == 0) {
						return true;
					}
			}
		}
	}
	return false;
}

void input() {

	ll n;
	cin >> n;
	ll*arr = new ll[n];
	for (ll i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	bool ans = xorr(arr, n);
	if (ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	input();
	return 0;
}