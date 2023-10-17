#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define pa pair <char , ll>

const ll N = 1001 , MOD = 111539786, inf = 1e15;

string str;
ll ans = 0 , nx[N][30] , f[N] , t;

void file() {
	freopen("RLESTR2.inp" , "r" , stdin);
	freopen("RLESTR2.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve() {
	vector <pa> a;
	cin >> str;
	ans = 0;
    a.pb({'a' , 1});
    for (ll i = 0 ; i < str.size() ; i++) {
  		char x = str[i];
  		ll res = 0;
  		while (str[i + 1] >= '0' && str[i + 1] <= '9' && i < str.size()) {
  			res = (res * 10 + (str[i + 1] - '0')) % MOD;
  			i++;
		}
		a.pb({x , res});
  	}
  	memset(f , 0 , sizeof (f));
  	memset(nx , -1 , sizeof (nx));
  	f[0] = 1;
  	for (ll i = a.size() ; i >= 1 ; i--) {
  		for (ll c = 0 ; c <= 25 ; c++) nx[i - 1][c] = nx[i][c];
  		if (i < a.size()) nx[i - 1][a[i].fi - 'a'] = i;
	}
  	for (ll i = 0 ; i < a.size() ; i++) {
  		ans = (ans + f[i] * a[i].se) % MOD;
  		if (i == str.size()) break;
  		for (ll c = 0 ; c <= 25 ; c++) {
  	    	ll j = nx[i][c];
  	  		if (j == - 1) continue;
			if (c == a[i].fi - 'a')	f[j] = (f[i] + f[j]) % MOD;
			else f[j] = (f[j] + a[i].se * f[i]) % MOD;
		}
  	}
 	cout << (ans - 1 + MOD) % MOD << '\n';
}

int main() {
	file();
	cin >> t;
	while (t--) solve();
	return 0;
}

