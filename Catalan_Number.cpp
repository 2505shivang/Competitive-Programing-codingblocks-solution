#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;


ll catalanNumber(ll n) {
	ll *arr = new ll[n + 1];
	arr[0] = 1;
	arr[1] = 1;

	for (ll i = 2; i <= n; ++i) {
		arr[i] = 0;
		for (ll j = 0; j < i; ++j) {
			arr[i] += arr[j] * arr[i - j - 1];
		}
	}
	return arr[n];
}

void input() {

	ll n;
	cin >> n;
	ll ans = catalanNumber(n);
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	input();
	return 0;
}