#include<bits/stdc++.h>
#define ll long long int
using namespace std;

float noOfPeople(float p) {
	if (p == 0) {
		return 1;
	}
	if (p == 1) {
		return 366;
	}
	ll x = 0;
	float p_compliment = 1;
	float num = 365;
	float denum = 365;
	while (p_compliment > 1 - p) {
		p_compliment = p_compliment * (num / denum);
		x++;
		num--;
	}

	return x;
}

void input() {
	float  p;
	cin >> p;
	float ans = noOfPeople(p);
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