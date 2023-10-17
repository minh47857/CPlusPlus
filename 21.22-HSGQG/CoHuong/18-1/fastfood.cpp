#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1505 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("fastfood.inp" , "r" , stdin);
	freopen("fastfood.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , bit[N] , ans[2 * N] , a[N][N] , b[N][N] , f[N][N] , g[N][N];
vector<int> v;
vector<pi> pos[N * N];

int get(int u) {
	int res = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i)))
		res = max(res , bit[i]);
	return res;
}

void update(int u , int val) {
	for(int i = u ; i <= n ; i += (i & (-i)))
		bit[i] = max(bit[i] , val);
}

void reload(int u) {
	for(int i = u ; i <= n ; i += (i & (-i)))
		bit[i] = 0;
}

void calc(int x , int s[N][N]) {
	for(pi p : pos[x]) {
		int i = p.fi , j = p.se;
		s[i][j] = get(j) + 1;
		update(j , s[i][j]);
	}
	for(pi p : pos[x]) reload(p.se);
}

void solve(int c[N][N] , int s[N][N]) {
	for(int x : v) pos[x].clear();
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			pos[c[i][j]].pb({i , j});
	for(int x : v) calc(x , s);
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j] , b[n - i + 1][n - j + 1] = a[i][j] , v.pb(a[i][j]);
	sort(v.begin() , v.end());
	v.erase(unique(v.begin() , v.end()) , v.end());
	solve(a , f);
	solve(b , g);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			ans[f[i][j] + g[n - i + 1][n - j + 1] - 1]++;
	for(int i = 1 ; i < 2 * n ; i++) cout << ans[i] << '\n';
	return 0;
}

