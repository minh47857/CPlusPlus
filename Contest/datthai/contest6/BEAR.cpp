#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e4 + 5 , M = 1e5 + 5 , inf = 1e15;

void file() {
	freopen("BEAR.inp" , "r" , stdin);
	freopen("BEAR.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node {
	ll u , v , w;
	bool operator < (const node&a) const {
		return w < a.w;
  }
};

ll n , m , a[N] , ans = 0 , par[N];
node edge[M];

int parent(int u) {
	if(par[u] < 0) return u;
	par[u] = parent(par[u]);
	return par[u];
}

bool merge(int x , int y) {
	if((x = parent(x)) == (y = parent(y))) return false;
	if(par[x] > par[y]) swap(x , y);
	par[x] += par[y];
	par[y] = x;
	return true;
}

int main() {
	file();
  cin >> n >> m;
  memset(par , -1 , sizeof(par));
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  for(int i = 1 ; i <= m ; i++) {
  	ll u , v , w;
  	cin >> u >> v >> w;
  	edge[i] = {u , v , 2 * w + a[u] + a[v]};
  }
  sort(edge + 1 , edge + m + 1);
  for(int i = 1 ; i <= m ; i++) {
  	if(merge(edge[i].u , edge[i].v)) ans += edge[i].w;
  }
  cout << ans + a[1];
  return 0;
}

