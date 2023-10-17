#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 , inf = 1e15;
struct node
{
	ll  u , v , c;
};
ll n , m , k , t  , d[N] , b[N] , w[N][N];
vector <node> ve;
bool operator < (const node&a , const node&b)
{
	return a.c < b.c ;
}
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub1
{
	ll par[101] , ans = 0;
int root(int v)
{
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
}

bool merge(int x, int y) 
{
    if ((x = root(x)) == (y = root(y)) )   return false ;
    if (par[y] < par[x])  swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
}
	void solve()
	{
		memset(par , -1 , sizeof(par));
		for (auto x : ve)	if (merge(x.u , x.v)) ans += x.c;
		cout << ans;
	}
}
namespace sub3
{
	ll ans = inf;
	void solve()
	{
	for (int kk = 1 ; kk <= n ; kk++)
	for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++)
	w[i][j] = min(w[i][j] , w[i][kk] + w[kk][j]);
	for (int i = 1 ; i <= n ; i++) ans = min(ans , w[i][b[1]] + w[i][b[2]] + w[i][b[3]]);
	cout << ans;
	}
	
}
namespace sub2
{
	void solve()
	{
	for (int kk = 1 ; kk <= n ; kk++)
	for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++)
	w[i][j] = min(w[i][j] , w[i][kk] + w[kk][j]);
	cout << w[b[1]][b[2]];
	}
}
namespace sub5
{
	
	ll par[101] , res = inf;
	vector <ll> v;
    int root(int v)
   {
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
   }

    bool merge(int x, int y) 
   {
    if ((x = root(x)) == (y = root(y)) )   return false ;
    if (par[y] < par[x])  swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
   }
	void cal()
	{
			memset(par , -1 , sizeof (par));
		    ll ans = 0;
		    bool check = true;
			for (auto x : ve)	if (d[x.u] == 0 && d[x.v] == 0 && merge(x.u , x.v)) ans += x.c ;
			for (int i = 1 ; i <= n ; i++) if(par[i] == -1 && d[i] == 0) check = false;
		   if (check) res = min(res , ans);
	}
	void gen(int t)
	{
		for (int i = 0 ; i <= 1 ; i++)
		{
			d[v[t - 1]] = i;
			if (t == k) cal();
			else gen(t + 1);
		}
	}
	void solve()
	{
		for (int i = 1 ; i <= n ; i++) if(d[i] == 1) v.pb(i);
		gen(1);
		cout << res ;
	}
}
namespace sub4
{
	struct nod
    {
        ll u , v , c;
    };
    bool operator > (const nod&a, const nod&b)
    {
        return a.c > b.c;
    }
	priority_queue< nod , vector<nod> , greater<nod>> heap;
	ll f[N][1200] , ans = inf , pos[N];
	void solve()
    {
    	memset(pos , -1 , sizeof(pos));
    	for (int i = 1 ; i <= k ; i++) pos[b[i]] = i - 1;
    	for (int i = 1 ; i <= n ; i++)
	    for (int j = 1 ; j < (1 << k) ; j++)
	    f[i][j] = inf;
        for (int i = 1 ; i <= n ; i++)
        {
        	if (pos[i] == -1) f[i][0] = 0 , heap.push({0 , i , 0});
        	else
			{
				f[i][(1 << pos[i])] = 0;
				 heap.push({0 , i , (1 << pos[i])});
			}
		}
		while(heap.size() != 0)
		{
			ll cp = heap.top().u;
			ll u = heap.top().v;
			ll t = heap.top().c;
			heap.pop();
			if (cp != f[u][t]) continue;
			for (ll i = t + 1 ; i < (1 << k) ; i++)
			{
				if ((i & t) == t)
				{
					ll nt = i ^ t ;
					if (pos[u] != -1 && !(nt & (1 << pos[u]))) nt = nt | (1 << pos[u]);
					if (f[u][i] > f[u][t] + f[u][nt])
					{
						f[u][i] = f[u][t] + f[u][nt];
						heap.push({f[u][i] , u , i});
					}
				}
			}
			for (ll i = 1 ; i <= n ; i++)
			{
				if (w[i][u] == inf || u == i) continue;
				if (pos[i] != -1 && !(t & (1 << pos[i])))
				{
					ll nt = t | (1 << pos[i]);
					if (f[i][nt] > w[i][u] + f[u][t])
					{
						f[i][nt] = w[i][u] + f[u][t];
						heap.push({f[i][nt] , i , nt});
					}
				}
				else
				{
					if (pos[i] == -1 && f[i][t] > f[u][t] + w[i][u])
					{
						f[i][t] = f[u][t] + w[i][u];
						heap.push({f[i][t] , i , t});
					}
				}
			}
		}
		for (int i = 1 ; i <= n ; i++) ans = min(ans , f[i][(1 << k) - 1]);
		cout << ans;
	}
	
}
int main()
{
	file();
  cin >> n >> k >> m  >> t;
  for (int i = 1 ; i <= k ; i++) cin >> b[i] , d[b[i]] = 1;
  for (int i = 1 ; i <= n ; i++) 
  for (int j = 1 ; j <= n ; j++)
  if (i != j ) w[i][j] = inf;
  for (int i = 1 ; i <= m ; i++)
  {
  	ll x , y , c;
  	cin >> x >> y >> c;
  	w[x][y] = min(c , w[x][y]);
  	w[y][x] = min(c , w[y][x]);
  	ve.push_back({x , y , c});
  }
  sort (ve.begin() , ve.end());
  if (t == 1 && k == n) sub1::solve();
  if (t == 1 && k == 2) sub2::solve();
  if (t == 1 && k == 3) sub3::solve();
  if (t == 1 && k <= 10 && k != n && k != 2 && k != 3) sub4::solve();
  if (t == 2 ) sub5::solve();
  
  return 0;
}

