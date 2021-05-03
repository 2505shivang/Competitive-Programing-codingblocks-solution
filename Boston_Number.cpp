#include<bits/stdc++.h>
#define ll long long int
#define max_val 10000005
using namespace std;

void seive(vector<ll>&prime) {
	bitset<max_val> arr;
	arr.set();
	arr[0] = 0;
	arr[1] = 0;
	for (ll i = 2; i < max_val ; i++) {

		if (arr[i]) {
			prime.push_back(i);
			for (ll j = i * i; j < max_val; j += i) {
				arr[j] = 0;
			}
		}

	}

	return;
}

ll digitSum(ll n) {
	if (n == 0) {
		return 0;
	}

	return (n % 10) + (digitSum(n / 10));
}


ll primeFactorSum(ll n) {
	vector<ll> prime;
	seive(prime);
	ll num = n;
	ll sum = 0;
	for (ll i = 0; prime[i]*prime[i] <= n; ++i) {
		if (n % prime[i] == 0) {
			while (n % prime[i] == 0) {
				sum += digitSum(prime[i]);
				n = n / prime[i];
			}
		}
	}

	if (n != 1) {
		sum += digitSum(n);
		n = n / 2;
	}

	return sum;

}


bool bostonNumber(ll n) {
	if (n <= 3) {
		return false;
	}

	ll p_sum = primeFactorSum(n);
	ll d_sum = digitSum(n);

	if (d_sum == p_sum) {
		return true;
	} else {
		return false;
	}


}

void input() {
	ll  n;
	cin >> n;
	bool ans = bostonNumber(n);
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