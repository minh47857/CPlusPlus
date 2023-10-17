#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 11 , MOD = 1e9 +7 , inf = 1e15;
ll n , m , f[37][1][2][3][4][5][6][7][8][9];
vector<pi> adj;
vector <ll> par , p;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool check(vector<ll> a , vector<ll> b)
{
	for (int i = 0 ; i < n ; i++) if (a[i] != b[i]) return false;
	return true;
}
ll cal (int t , vector<ll> pa)
{
	if (f[t][pa[0]][pa[1]][pa[2]][pa[3]][pa[4]][pa[5]][pa[6]][pa[7]][pa[8]] != -1) return f[t][pa[0]][pa[1]][pa[2]][pa[3]][pa[4]][pa[5]][pa[6]][pa[7]][pa[8]];
	if (t == m)
	{
		if (check(pa , par)) return 1;
		else return 0;
	}
	ll cnt = 0;
	vector<ll> paa = pa;
	cnt += cal(t + 1 , pa);
	ll u = adj[t].fi , v = adj[t].se;
	ll minpa = min(pa[u] , pa[v]);
    ll maxpa = max(pa[u] , pa[v]);
 	for (int j = 0 ; j < n ; j++) if(pa[j] == maxpa) pa[j] = minpa; 
 	cnt += cal(t + 1 , pa);
 	f[t][paa[0]][paa[1]][paa[2]][paa[3]][paa[4]][paa[5]][paa[6]][paa[7]][paa[8]] = cnt;
 	return cnt;
}
int main()
{
	file();
 cin >> n >> m;
 memset(f , -1 , sizeof(f));
 for (int i = 0 ; i <= 8 ; i++) par.pb(i) , p.pb(i);
 for (int i = 0 ; i < m ; i++)
 {
 	int u , v;
 	cin >> u >> v;
 	u-- , v--;
 	adj.pb({u , v});
 	ll minpa = min(par[u] , par[v]);
 	ll maxpa = max(par[u] , par[v]);
 	for (int j = 0 ; j < n ; j++) if(par[j] == maxpa) par[j] = minpa; 
 }
 cout << cal(0 , p);
 return 0;
}

