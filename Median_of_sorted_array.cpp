#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll solution(ll *arr1, ll *arr2, ll n) {
	ll i = 0;
	ll j = 0;
	ll cnt = -1;
	ll _1 = ((2 * n) - 1) / 2;
	ll _2 = ((2 * n) / 2);
	ll sum = 0;
	bool temp = 0;
	while (i < n && j < n) {
		if (arr1[i] > arr2[j]) {
			j++;
			temp = 0;
		} else {
			i++;
			temp = 1;
		}
		cnt++;
		if (cnt == _1 || cnt == _2) {
			if (temp == 0)
				sum += arr2[j - 1];
			else
				sum += arr1[i - 1];
		}
	}

	return sum / 2;

}

void input() {

	ll n;
	cin >> n;
	ll *arr1 = new ll[n];
	ll *arr2 = new ll[n];
	for (ll i = 0; i < n; ++i) {
		cin >> arr1[i];
	}
	for (ll i = 0; i < n; ++i) {
		cin >> arr2[i];
	}
	ll ans  = solution(arr1, arr2, n);
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