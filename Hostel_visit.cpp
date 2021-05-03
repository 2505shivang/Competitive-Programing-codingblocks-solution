#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void input() {

	ll q, k;
	cin >> q >> k;
	priority_queue<ll> pq;
	while (q--) {
		ll type, x, y;
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			pq.push((x * x) + (y * y));
		} else {
			while (pq.size() > k) {
				pq.pop();
			}
			cout << pq.top() << endl;
		}

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