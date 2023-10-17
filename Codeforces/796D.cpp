#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n , k , d , vis[N] , ans[N] , numedge;
queue<int> Q;
vector<pi> g[N];

int main() {
	cin >> n >> k >> d;
	for(int i = 1 , x ; i <= k ; i++) {
		cin >> x;
		Q.push(x);
		vis[x] = 1;
	}
	for(int i = 1 ; i < n ; i++) {
		int u , v;
		cin >> u >> v;
		g[u].pb({v , i}) ; g[v].pb({u , i});
	}
	while(Q.size()) {
		int u = Q.front();
		Q.pop();
		for(auto x : g[u]) {
			int v = x.fi , id = x.se;
			if(vis[v]) {
				if(!ans[id])
					ans[id] = 1 , numedge++;
			}
			else vis[v] = 1 , ans[id] = -1 , Q.push(v);
		}
	}
	cout << numedge << '\n';
	for(int i = 1 ; i < n ; i++) 
		if(ans[i] == 1) cout << i << ' ';
	return 0;
}

