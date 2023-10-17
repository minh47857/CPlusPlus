#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7,
          row[] = {1 , -1 , 0 , 0},
          col[] = {0 , 0 , 1 , -1};

using namespace std;

void file() {
	freopen("aquarium.inp" , "r" , stdin);
	freopen("aquarium.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct edge {
	int w , u , v;
	edge (int n_w = 0, int n_u = 0, int n_v = 0) {
		w = n_w , u = n_u , v = n_v;
	}
	bool operator < (const edge&s) const {
		return w < s.w;
	}
};

int n , m , par[N];
vector<vector<int>> a;
vector<vector<char>> s , res;
vector<edge> Edges;
ll ans = 0;

int id(int t , int u , int v) {
	return (t - 1) * m * n + (u - 1) * m + v;
}

int parent(int u) {
	if(par[u] < 0) return u;
	return (par[u] = parent(par[u]));
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
	a.resize(n + 1);
	s.resize(n + 1);
	res.resize(n + 1);
	for(int i = 1 ; i <= n ; i++)  
		s[i].resize(m + 1) , a[i].resize(m + 1) , res[i].resize(m + 1);
	for(int i = 1 ; i <= n ; i++) 
	  for(int j = 1 ; j <= m ; j++) 
	  	cin >> s[i][j];
//	for(int i = 1 ; i <= n ; i++)
//	  for(int j = 1 ; j <= m ; j++)
//	   cout << id(1 , i , j) << ' ' << id(2 ,i , j) << '\n';
	for(int u = 1 ; u <= n ; u++)
	  for(int v = 1 ; v <= m ; v++) {
	  	cin >> a[u][v] , Edges.pb({a[u][v] , u , v});
	  	for(int i = 0 ; i < 4 ; i++) {
			int nu = u + row[i] , nv = v + col[i] , nt , t;
			if(nu < 1 || nu > n || nv < 1 || nv > m) continue;
			if(s[nu][nv] == '/') {
				if(nu - u == 1 || nv - v == 1) nt = 1;
				else nt = 2;
			}
			else {
				if(u - nu == 1 || nv - v == 1) nt = 1;
				else nt = 2;
			}
			if(s[u][v] == '/') {
				if(u - nu == 1 || v - nv == 1) t = 1;
				else t = 2;
			}
			else {
				if(nu - u == 1 || v - nv == 1) t = 1;
				else t = 2;
			}
		//	cout << t << ' ' << u << ' ' << v << ' ' << nt << ' ' << nu << ' ' << nv << ' ' << id(t , u , v) << ' ' << id(nt , nu , nv) << '\n';
			merge(id(t, u , v) , id(nt , nu , nv));
		}
	}
//	cout << "hi";
	sort(Edges.begin() , Edges.end());
	for(auto x : Edges) {
		if(merge(id(1 , x.u , x.v) , id(2 , x.u , x.v))) ans += x.w , res[x.u][x.v] = '.';
		else res[x.u][x.v] = s[x.u][x.v];
		for(int i = 0 ; i < 4 ; i++) {
			int nu = x.u + row[i] , nv = x.v + col[i] , nt;
			if(nu < 1 || nu > n || nv < 1 || nv > m) continue;
			if(s[nu][nv] == '/') {
				if(nu - x.u == 1 || nv - x.v == 1) nt = 1;
				else nt = 2;
			}
			else {
				if(x.u - nu == 1 || nv - x.v == 1) nt = 1;
				else nt = 2;
			}
			merge(id(1 , x.u , x.v) , id(nt , nu , nv));
		}
	}
	cout << ans << '\n';
	for(int i = 1 ; i <= n ; i++) {
	  for(int j = 1 ; j <= m ; j++)
	   	cout << res[i][j];
	   cout << '\n';
	}
	return 0;
}


