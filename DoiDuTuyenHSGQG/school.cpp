#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 2e5 + 5 , inf = 1e9;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 int d[N] , a[N] , n , m , q , x[N] , y[N] , st[4 * N];
vector<int> adj[N];

void Bfs()
{
	queue<int> q;
	for (int i = 1 ; i < n ; i++) d[i] = inf;
	d[n] = 0;
	q.push(n);
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(auto x : adj[u]) 
		{
			if (d[x] == inf)
			{
				d[x] = d[u] + 1;
				q.push(x);
			}
		}
	}
}

void build(int id , int l , int r)
{
	if(l == r)
	{
		st[id] = l - 1 + d[a[l]];
		return ;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
//	cout << l << ' ' << r << ' ' << st[id] << endl;
}

void update(int id , int l , int r , int pos)
{
	if(l > pos || r < pos) return;
	if(l == r)
	{
		st[id] = l - 1 + d[a[l]];
		return ;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , pos);
	update(id * 2 + 1 , mid + 1 , r , pos);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
	
}

int main()
{
	file();
  cin >> n >> m >> q;
   for (int i = 1 ; i <= m ; i++)
  {
  	int u , v;
  	cin >> u >> v;
  	adj[v].pb(u);
  }
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  for (int i = 1 ; i <= q ; i++) cin >> x[i] >> y[i];
  Bfs();
  build(1 , 1 , n );
 // cout << st[1] << ' ';
  for (int i = 1 ; i <= q ; i++) 
  {
    swap(a[x[i]] , a[y[i]]);
    update(1 , 1 , n , x[i]);
    update(1 , 1 , n , y[i]);
    cout << st[1] << '\n';
  }
  return 0;
}

