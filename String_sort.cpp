#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;


bool compare(string a, string b) {
	if (a.find(b) == 0 || b.find(a) == 0) {
		return a.size() > b.size();
	}

	return a < b;

}
void solution(string *arr, ll n) {
	if (n == 0 || n == 1) {
		return ;
	}

	sort(arr, arr + n, compare);
	return;
}

void input() {

	ll n;
	cin >> n;
	string *arr = new string[n];
	for (ll i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	solution(arr, n);

	for (ll i = 0; i < n; ++i) {
		cout << arr[i] << endl;
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