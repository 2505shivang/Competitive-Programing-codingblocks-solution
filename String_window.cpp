#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string common_substr(string str1, string str2) {
	unordered_map<char, int> mymap_str1;
	unordered_map<char, int> mymap_str2;
	for (ll i = 0; i < str2.size(); ++i) {
		mymap_str2[str2[i]]++;
	}
	ll cnt = 0;
	ll idx = -1;
	ll minlen = INT_MAX;
	ll i = 0, j = 0;
	while (i < str1.size() && j < str1.size()) {
		mymap_str1[str1[i]]++;
		if (mymap_str2[str1[i]] != 0 && mymap_str1[str1[i]] <= mymap_str2[str1[i]]) {
			cnt++;
		}


		if (cnt == str2.size()) {
			ll start = j;
			while (mymap_str2[str1[start]] == 0 || mymap_str1[str1[start]] > mymap_str2[str1[start]]) {
				if (mymap_str1[str1[start]] > mymap_str2[str1[start]]) {
					mymap_str1[str1[start]]--;
				}
				start++;
			}
			ll len = i - start + 1;
			if (len < minlen) {
				idx = start;
				minlen = len;
			}
			j = start;
		}
		i++;
	}

	if (idx == -1) {
		return "No String";
	}
	return str1.substr(idx, minlen);
}

void input() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	string ans = common_substr(str1, str2);
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