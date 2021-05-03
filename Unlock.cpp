#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void unlock(ll*arr, ll n, ll k) {
	priority_queue<ll> pq;
	unordered_map<ll, ll> index;
	for (ll i = 0; i < n; ++i) {
		pq.push(arr[i]);
		index[arr[i]] = i;
	}

	ll cnt = 0;

	for (ll i = 0; i < n; ++i) {
		ll num = pq.top();
		pq.pop();
		if (arr[i] != num) {
			swap(arr[i], arr[index[num]]);
			swap(index[arr[i]], index[arr[index[num]]]);
			cnt++;
		}
		if (cnt == k) {
			break;
		}
	}

	return;

	return;

}

void input() {
	ll n, k;
	cin >> n >> k;
	ll* arr = new ll[n];
	for (ll i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	unlock(arr, n, k);
	for (ll i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
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