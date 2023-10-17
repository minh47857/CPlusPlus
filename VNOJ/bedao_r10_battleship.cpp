#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , lmin = inf , lmax = -inf , rmin = inf , rmax = -inf , t , res[N] , a[N];
vector<int> adj[N];

void dfs(int i) {
	for(auto j : adj[i]) if(!res[j]) {
		res[j] = t;
		dfs(j);
	}
}

int main() {
	file();
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] <= (m + 1) / 2) lmin = min(lmin , a[i]) , lmax = max(lmax , a[i]);
		else rmin = min(rmin , a[i]) , rmax = max(rmax , a[i]);
	}
	// 1 2 3 4 5 6 7
	for(int i = 1 ; i < max(lmax , m - rmin + 1) ; i++) 
		adj[i].pb(m - i + 1) , adj[m - i + 1].pb(i);
	for(int i = lmin + 1 ; i <= (m + 1) / 2 ; i++) 
		adj[i].pb(m - i + 2) , adj[m - i + 2].pb(i);
	for(int i = rmax - 1 ; i >= (m + 1) / 2 ; i--)
		adj[i].pb(m - i) , adj[m - i].pb(i);
	for(int i = 1 ; i <= m ; i++) 
		if(!res[i]) res[i] = ++t , dfs(i);
	for(int i = 1 ; i <= m ; i++) cout << res[i] << ' ';
	return 0;
}

