#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 20 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    //freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N];
pi f[1 << N][N];

void GetMax(int u , int t1 , int v , int t2) {
	
	if(f[u][t1].fi == f[v][t2].fi + abs(a[t2] - a[t1])) f[u][t1].se += f[v][t2].se;
	else if(f[u][t1].fi < f[v][t2].fi + abs(a[t2] - a[t1])) f[u][t1] = {f[v][t2].fi + abs(a[t2] - a[t1]) , f[v][t2].se};
}

int Bit(int x , int k) {
	return (x >> k) & 1;
}

void solve() {
	m = (1 << n) - 1;
	for(int mask = 1 ; mask <= m ; mask++)
	    for(int i = 0 ; i <= n ; i++) f[mask][i] = {0 , 0};
	for(int i = 0 ; i < n ; i++) f[1 << i][i] = {a[i] , 1};
	for(int mask = 1 ; mask <= m ; mask++) {
		for(int t = 0 ; t < n ; t++) {
			if(!Bit(mask , t)) continue;
			
			for(int i = 0 ; i < n ; i++) if(!Bit(mask , i)) {
		    int nmask = mask | (1 << i);
		        GetMax(nmask , i , mask , t);
		    }
		}	
	}
	for(int i = 0 ; i < n ; i++) 	GetMax(m , n , m , i);
	cout << f[m][n].fi + 2 * n << ' ' << f[m][n].se << '\n';
}

int main() {
		while(cin >> n) {
			if(!n) return 0;
			for(int i = 0 ; i < n ; i++) cin >> a[i];
			a[n] = 0;
			solve();
		}
}


