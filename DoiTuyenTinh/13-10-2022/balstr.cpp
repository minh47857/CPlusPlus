#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 30 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("balstr.inp" , "r" , stdin);
	freopen("balstr.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , n , d1[N] , d2[N];
string s;

void solve() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	bool ans = true;
	memset(d1 , 0 , sizeof(d1));
	memset(d2 , 0 , sizeof(d2));
	for(int i = 1 ; i <= n / 2 ; i++) d1[s[i] - 'a']++;
	for(int i = n / 2 + 1 ; i <= n ; i++) d2[s[i] - 'a']++;
	for(int i = 0 ; i <= 25 ; i++) 
		if(!min(d1[i] , d2[i]) && max(d1[i] , d2[i])) ans = false;
	cout << ((ans) ? "YES\n" : "NO\n");
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

