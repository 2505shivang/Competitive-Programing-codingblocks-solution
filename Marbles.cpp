#include<bits/stdc++.h>
#define ll long long int
#define max_val 10000005
using namespace std;

ll marbles(ll n, ll k) {
	if (n == k || k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}

	if (k > n / 2) {
		k = n - k;
	}

	ll ans = 1;
	ll dnum = 1;
	for (ll i = n; i > n - k; i--) {
		ans = ans * i;
		ans = ans / dnum;
		dnum++;
	}



	return ans;
}

void input() {
	int t;
	cin >> t;
	while (t--) {
		ll  n, k;
		cin >> n >> k;
		ll ans = marbles(n - 1, k - 1);
		cout << ans << endl;
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