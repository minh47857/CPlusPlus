#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("dayngoac.inp" , "r" , stdin);
	freopen("dayngoac.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , n , pre[N] , f[N];
string s;

void solve() {
	ll ans = 0;
	cin >> s;
	s = ' ' + s;
	n = s.size() - 1;
	for(int i = 1 ; i <= n ; i++) 
		pre[i] = pre[i - 1] + ((s[i] == '(') ? 1 : -1);
	for(int i = 1 ; i <= n ; i++)
		if(pre[i] >= 1) f[i] = f[i - 1] + 1;
		else f[i] = 0;
	for(int i = 1 ; i <= n ; i++) 
		ans += n - i + 2 + f[i - 1];
	cout << ans + 1 << '\n';	
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

