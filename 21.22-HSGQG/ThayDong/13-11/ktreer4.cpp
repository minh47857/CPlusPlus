#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll k , h , n , ans = 0;
vector<pi> Q;

ll par(ll x) {
	return (x + k - 2) / k;
}

int main() {
	file();
	cin >> k >> h >> n;
	for(int i = 1 ; i <= n ; i++) {
		ll x , p;
		cin >> x;
		p = x;
		int tang = 0;
		while(x != 1) x = par(x) , tang++;
		Q.pb({p , tang});
	}
	sort(Q.begin() , Q.end());
	Q.erase(unique(Q.begin() , Q.end()) , Q.end());
	while(Q.size() > 1) {
		vector<pi> E;
		int MaxH = 0;
		for(auto x : Q) MaxH = max(MaxH , x.se);
		for(auto x : Q) {
			if(x.se == MaxH) E.pb({par(x.fi) , x.se - 1}) , ans++;
			else E.pb(x);
		}
		Q.clear();
		sort(E.begin() , E.end());
		E.erase(unique(E.begin() , E.end()) , E.end());

		Q = E;
	}
	cout << ans + 1;
	return 0;
}

