#include<bits/stdc++.h>
#define ll long long int
#define max_val 10000005
using namespace std;

// Be carefull beacuse factorial could reach beyond the long long limit therefore
// divide higher number first
vector<ll> primes;
void sieve() {
	bitset<max_val> b;
	b.set();
	b[0] = 0;
	b[1] = 0;
	for (ll i = 2; i < max_val; ++i) {
		if (b[i]) {
			primes.push_back(i);
			for (ll j = i * i; j < max_val; j += i) {
				b[j] = 0;
			}
		}
	}

	return;
}

void primefactor(ll n, vector<pair<ll, ll>>&prime) {
	for (ll i = 0; primes[i]*primes[i] <= n; ++i) {
		if (n % primes[i] == 0) {
			ll cnt = 0;
			while (n % primes[i] == 0) {
				cnt++;
				n = n / primes[i];
			}
			prime.push_back(make_pair(primes[i], cnt));
		}

	}
	if (n != 1) {
		prime.push_back(make_pair(n, 1));
	}
	return;
}

ll solution(ll n, ll k) {
	vector<pair<ll, ll>> primefactors;
	primefactor(k, primefactors);
	ll ans = INT_MAX;
	for (ll i = 0; i < primefactors.size(); ++i) {
		ll cnt = 0;
		ll temp = n;
		ll c_prime = primefactors[i].first;
		while (temp / c_prime) {
			cnt += (temp / c_prime);
			c_prime *= primefactors[i].first;
		}
		if (cnt == 0) {
			continue;
		}
		ans = min(ans, cnt / primefactors[i].second);
	}

	if (ans == INT_MAX) {
		return 0;
	}

	return ans;
}

void input() {
	int t;
	cin >> t;
	sieve();
	while (t--) {
		ll  n, k;
		cin >> n >> k;
		ll ans = solution(n, k);
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