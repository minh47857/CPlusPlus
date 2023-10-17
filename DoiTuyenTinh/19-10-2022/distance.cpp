#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("distance.inp" , "r" , stdin);
	freopen("distance.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int t , n;
pi prea[N] , preb[N] , sufa[N] , sufb[N];
string s;

int main() {
	file();
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for(int i = 1 ; i <= n ; i++) {
		prea[i] = prea[i - 1] , preb[i] = preb[i - 1];
		if(s[i] == 'A') prea[i].fi += i , prea[i].se++;
		else preb[i].fi += i , preb[i].se++;
	}
	for(int i = n ; i >= 1 ; i--) {
		sufa[i] = sufa[i + 1] , sufb[i] = sufb[i + 1];
		if(s[i] == 'A') sufa[i].fi += i , sufa[i].se++;
		else sufb[i].fi += i , sufb[i].se++;
	}
	cin >> t;
	while(t--) {
		ll x ; cin >> x;
		cout << -prea[x - 1].fi + x * prea[x - 1].se - x * sufa[x + 1].se + sufa[x + 1].fi << ' ';
		cout << -preb[x - 1].fi + x * preb[x - 1].se - x * sufb[x + 1].se + sufb[x + 1].fi << '\n';
	}
	return 0;
}

