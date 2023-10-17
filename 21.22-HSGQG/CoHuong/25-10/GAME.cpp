#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 505 , M = 2e5;

void file() {
	freopen("GAME.inp" , "r" , stdin);
	freopen("GAME.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , m , ans[N] , par[N];
pi Edge[M];

int parent(int u) {
	if(par[u] < 0) return u;
	par[u] = parent(par[u]);
	return par[u];
}

bool merge(int u , int v) {
	if((u = parent(u)) == (v = parent(v))) return false;
	if(par[u] > par[v]) swap(u , v);
	par[u] += par[v];
	par[v] = u;
	return true;
}
void solve() {
	cin >> n;
	m = n * (n - 1) / 2;
	for(int i = 1 ; i <= m ; i++) cin >> Edge[i].fi >> Edge[i].se;
	memset(par , -1 , sizeof(par));
	for(int i = m ; i >= 1 ; i--) {
		if(merge(Edge[i].fi , Edge[i].se)) ans[i] = 1;
		else ans[i] = 0;
	}
	for(int i = 1 ; i <= m ; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	file();
  cin >> t ;
  while(t--) solve();
}

