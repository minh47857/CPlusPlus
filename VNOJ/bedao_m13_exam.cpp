#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int q , t , d[N] , p[N] , x[N];

void solve() {
	cin >> q;
	bool ans = true;
	for(int i = 1 ; i <= q ; i++) cin >> p[i] >> x[i];
	for(int i = 1 ; i <= q ; i++) {
		if(p[i] == 1) d[x[i]]++;
		if(p[i] == 2) {
			if(d[x[i]]) d[x[i]]--;
			else {
				if(!d[0]) {ans = false ; break;}
				else d[0]--;
			}
		}
	}
	for(int i = 1 ; i <= q ; i++) d[x[i]] = 0;
	cout << ((ans) ? "YES\n" : "NO\n");
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

