#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , inf = 1e15;

void file() {
	freopen("trans.inp" , "r" , stdin);
	freopen("trans.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , k , d[N];
vector<int> G[N];

void Bfs() {
	queue<int> Q;
	Q.push(1);
	d[1] = 0;
	while(Q.size()) {
		int u = Q.front();
		Q.pop();
		for(auto v : G[u]) 
			if(v != 1 && !d[v]) d[v] = d[u] + 1 , Q.push(v);
	}
}

bool check(ll x) {
	ll res = 0;
	for(int i = 2 ; i <= n ; i++)  {
		res += (x / d[i]);
		if(res >= k) return true;
	}
	return false; 
}

int main() {
	file();
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++) {
		int u , v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	Bfs();
	ll d = 0 , c = inf , g , ans;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}

