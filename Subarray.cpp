#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


ll subarray(ll *arr, ll n) {
	if (n == 1) {
		return arr[0];
	}

	ll sum = 0;
	ll j = 0;
	set<ll> s;
	for (ll i = 0; i < n; ++i) {
		while (j < n && s.find(arr[j]) == s.end()) {
			s.insert(arr[j]);
			j++;
		}
		ll len = j - i + 1;
		sum = sum + (len * (len - 1)) / 2;
		s.erase(arr[i]);
	}

	return sum % mod;
}

void input() {
	ll n;
	cin >> n;
	ll* arr = new ll[n];
	for (ll i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	ll ans = subarray(arr, n);
	cout << ans << endl;
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	input();
	return 0;
}