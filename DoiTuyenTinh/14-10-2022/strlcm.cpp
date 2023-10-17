#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("strlcm.inp" , "r" , stdin);
	freopen("strlcm.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int q;
string s , t;

bool check(int l , string x) {
	if(x.size() % l) return false;
	for(int i = l ; i < x.size() ; i++)
		if(x[i] != x[i - l]) return false;
	return true;
}

void solve() {
	cin >> s >> t;
	for(int i = min(s.size() , t.size()) ; i >= 1 ; i--) 
		if(check(i , s) && check(i , t)) {
			if(s.substr(0 , i) != t.substr(0 , i)) continue;
			int lcm = int(s.size()) / i * int(t.size()) / i;
			string ans = s.substr(0 , i);
			while(lcm--) cout << ans;
			cout << '\n';
			return;
		}
	cout << -1 << '\n';
}

int main() {
	file();
	cin >> q;
	while(q--) solve();
	return 0;
}

