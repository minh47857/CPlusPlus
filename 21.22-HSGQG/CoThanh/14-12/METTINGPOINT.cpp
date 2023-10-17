#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>

const ll N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e18;

ll n , m , k , v1[N] , v2[N] , d1[N] , d2[N] , pre[N] , suf[N];
pi a[N];
vector<pi> G[N];

void Dijkstra(ll d[] , int s) {
	priority_queue< pi , vector<pi>  , greater<pi> > Q;
	for(int i = 1 ; i <= n ; i++) 
		d[i] = inf;
	d[s] = 0;
	Q.push({0 , s});
	while(Q.size()) {
		ll u = Q.top().se , du = Q.top().fi;
		Q.pop();
		if(d[u] != du) continue;
		for(auto x : G[u]) {
			ll v = x.fi , w = x.se;
			if(d[v] > du + w) 
				d[v] = du + w , Q.push({d[v] , v});
		}
	}
}

bool cmp(pi a , pi b) {
	return (a.fi * b.se < b.fi * a.se);
}

ll solve(ll vA , ll vB) {
	ll ans = inf;
	int d = 1 , c = n , g , pos = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(a[g].fi * vA >= a[g].se * vB) pos = g , c = g - 1;
		else d = g + 1;
	}
	if(pos != -1) 
		ans = min(ans , suf[pos] * vA);
	d = 1 , c = n , pos = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(a[g].fi * vA <= a[g].se * vB) pos = g , d = g + 1;
		else c = g - 1;  
	}
	if(pos != -1)
		ans = min(ans , pre[pos] * vB);
	return ans;
}

int main() {
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		G[u].pb({v , w});
		G[v].pb({u , w});
	}
	Dijkstra(d1 , 1);
	Dijkstra(d2 , n);
	for(int i = 1 ; i <= k ; i++) 
		cin >> v1[i] >> v2[i];
	for(int i = 1 ; i <= n ; i++)
		a[i] = {d1[i] , d2[i]} ;
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1 ; i <= n ; i++)
	pre[0] = suf[n + 1] = inf;
	for(int i = 1 ; i <= n ; i++) 
		pre[i] = min(pre[i - 1] , a[i].se);
	for(int i = n ; i >= 1 ; i--)
		suf[i] = min(suf[i + 1] , a[i].fi);
	for(int i = 1 ; i <= k ; i++)
		cout << solve(v1[i] , v2[i]) << '\n';
	return 0;
}

