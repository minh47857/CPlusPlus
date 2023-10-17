#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<ll , ll>
using namespace std;

const int N = 2e5 + 5 , MOD = 998244353;
const ll inf = 1e17;

void file() {
//	freopen(".inp" , "r" , stdin);
//	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k;
ll ans = 1 , d[N] , f[N] , Pow[N];
vector<pi> adj[N];
pi Edge[N];

void Dijkstra() {
	priority_queue<pi , vector<pi> , greater<pi> > Q;
	for(int i = 2 ; i <= n ; i++) 
		d[i] = inf , f[i] = 0;
	d[1] = 0 , f[1] = 1;
	Q.push({0 , 1});
	while(Q.size()) {
		ll u = Q.top().se , du = Q.top().fi;
		Q.pop();
		if(du != d[u]) continue;
		for(auto x : adj[u]) {
			int v = x.fi , w = x.se;
			if(d[v] == d[u] + w) {
				f[v] = (f[v] + f[u]) % MOD;
			}
			else if(d[v] > d[u] + w) {
				f[v] = f[u];
				d[v] = d[u] + w;
				Q.push({d[v] , v});
			}
		}
	}
}

int main() {
	file();
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++) {
		ll u , v , c ; cin >> u >> v >> c;
		adj[u].pb({v , c}) , adj[v].pb({u , c});
	}
	for(int i = 1 ; i <= k ; i++) {
		ll v , c ; cin >> v >> c;
		adj[1].pb({v , c}) , adj[v].pb({1 , c});
		Edge[i] = {v , c};
	}
	Dijkstra();
	Pow[0] = 1;
	for(int i = 1 ; i <= k ; i++)
		Pow[i] = Pow[i - 1] * 2 % MOD;
	sort(Edge + 1 , Edge + k + 1);
	for(int i = 1 ; i <= k ; i++) {
		ll dem = 1;
		while(i < k && Edge[i].fi == Edge[i + 1].fi && Edge[i].se == Edge[i + 1].se) dem++ , i++;
		if(d[Edge[i].fi] == Edge[i].se && f[Edge[i].fi] == dem) ans = ans * (Pow[dem] - 1 + MOD) % MOD;
		else ans = ans * Pow[dem] % MOD;	
	}
	cout << ans;
	return 0;
}
