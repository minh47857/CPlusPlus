#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define pb push_back

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("SMARTCOMP.inp" , "r" , stdin);
	freopen("SMARTCOMP.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m = 0 , ans = 0 , c[5][N] , v[5][N] , V , f[N * N];
pi a[N * N] , b[N * N];

int binary(ll x) {
	int d = 1 , c = m , kq = -1 , g;
	while(d <= c) {
		g = (d + c) / 2;
		if(b[g].fi <= x) kq = g , d = g + 1;
		else c = g - 1;
	}
	return kq;
}

bool cmp(pi a , pi b) {
	if(a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}

int main() {
	file();
	cin >> n >> V;
	for(int j = 1 ; j <= 4 ; j++)
	for(int i = 1 ; i <= n ; i++) cin >> c[j][i] >> v[j][i];
	for(int i = 1 ; i <= n ; i++) 
	  for(int j = 1 ; j <= n ; j++)
	    a[++m] = { c[1][i] + c[2][j] , v[1][i] + v[2][j]},
	    b[m] = {c[3][i] + c[4][j] , v[3][i] + v[4][j]};
	sort(a + 1 , a + m + 1 , cmp);
	sort(b + 1 , b + m + 1 , cmp);
	f[0] = 0;
	for(int i = 1 ; i <= m ; i++) f[i] = max(f[i - 1] , b[i].se);	
	for(int i = 1 ; i <= m ; i++) {
	int	id = binary(V - a[i].fi);
		if(id != -1) ans = max(ans , f[id] + a[i].se);
	}
	cout << (ans) ? ans : -1;
	return 0;
}


