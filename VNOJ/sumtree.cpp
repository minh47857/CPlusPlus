#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll n , S , ans , d[N] , a[N];
vector<int> G[N];
map<ll , int> f;

void Dfs(int u) {
	ans += f[d[u] - S];
	f[d[u]]++;
	for(auto v : G[u]) {
		d[v] = d[u] + a[v];
		Dfs(v);
	}
	f[d[u]]--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> S;
	for(int i = 1 , u ; i <= n ; i++) {
		cin >> u >> a[i];
		G[u].pb(i);
	}
	f[0] = 1; d[1] = a[1];
	Dfs(1);
	cout << ans;
	return 0;
}

