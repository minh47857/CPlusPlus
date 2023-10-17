#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("BLOCK.inp" , "r" , stdin);
	freopen("BLOCK.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , ans = 0 , par[N] , check[N];

struct node {
	int u , v , w;
	bool operator > (const node&s) const {return w > s.w;}
} Edge[N];

int parent(int u) {
	if(par[u] < 0) return u;
	par[u] = parent(par[u]);
	return par[u];
}

bool merge(int x , int y) {
	x = parent(x) , y = parent(y);
	if(check[x] && check[y]) return false;
	if(par[x] > par[y]) swap(x , y);
	par[x] += par[y];
	par[y] = x;
	check[x] |= check[y];
	return true;
}

int main() {
	file();
	cin >> n;
	memset(par , -1 , sizeof(par));
	for(int i = 1 ; i < n ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
	    Edge[i] = {u , v , w};
	}
	cin >> t;
	for(int i = 1 , x ; i <= t ; i++) cin >> x , check[x] = 1;
	sort(Edge + 1 , Edge + n , greater<node>());
	for(int i = 1 ; i < n ; i++)
		if(!merge(Edge[i].u , Edge[i].v))  ans += Edge[i].w;
	cout << ans;
	return 0;
}


