#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e5 + 5;

int n , cnt = 0 , dem , vis[N];
set<pi> s;
pi a[N];
vector<int> G[N];

void Dfs(int u) {
	dem++;
	vis[u] = 1;
	for(auto v : G[u])
		if(!vis[v]) Dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		if(cnt >= n) break;
		auto it = s.lower_bound({a[i].fi , 0});
		for( ; it != s.end() ; it++) {
			if((*it).fi >= a[i].se) break;
			cnt++;
			G[(*it).se].pb(i);
			G[i].pb((*it).se);
			if(cnt >= n) break;
		}
		s.insert({a[i].se , i});
	}
	Dfs(1);
	cout << ((cnt == n - 1 && dem == n) ? "YES" : "NO");
	return 0;
}

