#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

string s , t;
int l , y[30] , x[30];
ll ans = 0;

bool check() {
	for(int i = 0 ; i <= 27 ; i++)
		if(x[i] > y[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> s >> t;
	s = ' ' + s , t = ' ' + t;
	for(int i = 1 ; i < t.size() ; i++) y[t[i] - 'a']++;
	l = 1;
	for(int i = 1 ; i < s.size() ; i++) {
		x[s[i] - 'a']++;
		while(!check() && l <= i) {
			x[s[l] - 'a']--;
			l++;
		}
		 ans += (i - l + 1);
	}
	cout << ans;
	return 0;
}

