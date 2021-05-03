#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll n, ll p) {
	if (p == 0) {
		return 1;
	}

	ll smallans = power(n, p / 2);

	if (p % 2 == 0) {
		return smallans * smallans;
	} else {
		return n * smallans * smallans;
	}
}

void input() {
	ll n , p;
	cin >> n >> p;
	ll ans = power(n, p);
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