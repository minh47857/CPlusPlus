#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10005 , M = 1000005;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , q , deg[N] ,res[M] , u[N];
bool c[10000][10000];
vector<pair<int , int>> query[N];

void solve1(int u)
{
	for(auto x : query[u])
	{
		if(x.fi == u)
		{
			res[x.se] = 0;
			continue;
		}
		
		if(!c[u][x.fi]) res[x.se] = 1;
		else res[x.se] = 2;
	}
}

void solve2(int s)
{
	int sl = n , dist[N];
	memset(dist , -1 , sizeof(dist));
	for(int i = 0 ; i < n ; i++) u[i] = i;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size())
	{
		int k = q.front();
		q.pop();
		for(int i = 0 ; i < sl ; i++)
		{
			if(dist[u[i]] == -1 && !c[k][u[i]])
			   {
			   	dist[u[i]] = dist[k] + 1;
			   	q.push(u[i]);
			   	swap(u[i] , u[sl - 1]);
			   	sl-- , i--;
			   }
		}
	}
	
	for(auto x : query[s])
	{
		if(x.fi == s) res[x.se] = 0;
		else 	res[x.se] = dist[x.fi];
	}
}

int main()
{
	file();
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++) 	deg[i] = n - 1;
  
  for(int i = 1 ; i <= m ; i++)
  {
  	int u , v;
  	cin >> u >> v;
  	deg[u]-- , deg[v]--;
  	c[u][v] = true , c[v][u] = true;
  }
  
  cin >> q;
  for(int i = 1 ; i <= q ; i++)
  {
  	int u , v;
  	cin >> u >> v;
  	if(deg[u] > deg[v]) swap(u , v);
  	query[u].pb({v , i});
  }
  
  for(int i = 0 ; i < n ; i++)
  {
  		if(deg[i] >= n / 2) solve1(i);
  		else solve2(i);
  }
  for(int i = 1 ; i <= q ; i++) cout << res[i] << '\n';
  return 0;
}

