#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

multiset<int> s[N];
int n , a[N] , pa , id[N];
vector<int> g[N];

void Dfs(int u) {
	for(auto v : g[u]) {
		Dfs(v);
		if(s[id[v]].size() > s[id[u]].size()) id[u] = id[v];
	}
	for(auto v : g[u]) 
		if(id[v] != id[u]) 
			for(auto x : s[id[v]]) s[id[u]].insert(x);
	
	if(s[id[u]].size() && a[u] <= *s[id[u]].rbegin() ) {
		auto it = s[id[u]].lower_bound(a[u]);
		s[id[u]].erase(it);
	}
	s[id[u]].insert(a[u]);
}

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> pa;
		g[pa].pb(i);
		id[i] = i;
	}
	Dfs(1);
	cout << s[id[1]].size();
}

