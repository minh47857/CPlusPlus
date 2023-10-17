#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("BTCD.inp" , "r" , stdin);
	freopen("BTCD.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node
{
	int c , fi , se;
};

bool operator < (const node&a , const node&b)
{
	return a.c > b.c;
}

int par[N] , n , m , k , res[N];
vector<node> Q;
set<int> query[N];

int parent(int u)
{
	if(par[u] < 0) return u;
	par[u] = parent(par[u]);
	return par[u];
}

void merge(int u , int v , int w)
{
	if( (u = parent(u)) == (v = parent(v)) ) return ;
	if(par[u] > par[v]) swap(u , v);
	par[u] += par[v];
	par[v] = u;
	for(auto x : query[v])
	{
		auto p = query[u].find(x);
		if(p != query[u].end())
		{
			res[x] = w;
			query[u].erase(x);
		}
		else query[u].insert(x);
	}
}

int main()
{
	file();
  cin >> n >> m;
  for (int i = 1 ; i <= m ; i++) 
  {
  	int u , v , w;
  	cin >> u >> v >> w;
  	Q.pb({w , u , v});
  }
  sort(Q.begin() , Q.end());
  cin >> k;
  for (int i = 1 ; i <= k ; i++)
  {
  	int u , v;
  	cin >> u >> v;
  	query[u].insert(i);
  	query[v].insert(i);
  }
  memset(par , -1 , sizeof(par));
  for (auto x : Q)  merge(x.fi , x.se , x.c);
  for (int i = 1 ; i <= k ; i++) cout << res[i] << '\n';
  return 0;
}

