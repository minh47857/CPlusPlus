#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 30 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("replace.inp" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , res , ans , vis[N];
vector<int> g[N];
string s , t;

void dfs(int u) {
	res++;
	for(auto v : g[u]) if(!vis[v]) {
		vis[v] = 1;
		dfs(v);
	}
}

int main() {
	file();
	cin >> n >> s >> t;
	for(int i = 0 ; i < n ; i++) {
		g[s[i] - 'a'].pb(t[i] - 'a');
		g[t[i] - 'a'].pb(s[i] - 'a');
	}
	for(int i = 0 ; i <= 25 ; i++) if(!vis[i]) {
		res = 0; 
		vis[i] = 1;
		dfs(i);
		ans += res - 1;
	}
	cout << ans;
	return 0;
}

