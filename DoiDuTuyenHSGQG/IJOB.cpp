#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 2e5 + 5 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct job {
	ll w , t;
	bool operator < (const job&a) const {
		return w * a.t > a.w * t;
	}
};

ll n , ans = 0 , id[N] , Time = 0;
vector<int> adj[N];
multiset<job> s[N];
job a[N];

void Dfs(int u ) {
	id[u] = u;
	for(auto v : adj[u]) {
		Dfs(v);
		if(s[id[v]].size() > s[id[u]].size()) id[u] = id[v];
	}
	
	for(auto v : adj[u]) {
		if(id[v] == id[u]) continue;
		for(auto x : s[id[v]]) s[id[u]].insert(x);
	}
	
	ll W = a[u].w , T = a[u].t;
	while(!s[id[u]].empty()) {
		job x = *s[id[u]].begin();
		if(W * x.t >= x.w * T) break;
		s[id[u]].erase(s[id[u]].begin());
		ans += x.w * T;
		T += x.t;
		W += x.w;
	}
	
	s[id[u]].insert({W , T});
}

int main() {
	file();
  cin >> n;
  for(int i = 0 , x; i < n ; i++) {
  	cin >> x ;
	if(x != -1) adj[x].pb(i);
  }
  for(int i = 0 ; i < n ; i++) cin >> a[i].w;
  for(int i = 0 ; i < n ; i++) cin >> a[i].t , ans += a[i].w * a[i].t;
  Dfs(0);
  for(auto x : s[id[0]]) {
  	ans += Time * x.w;
  	Time += x.t;
  }
  cout << ans;
  return 0;
}

