#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1005 , inf = 1e15 ,
      row[4] = {0 , 1 , -1 , 0} ,
      col[4] = {1 , 0 , 0 , -1} ;
void file()
{
	freopen("FAIR.inp" , "r" , stdin);
	freopen("FAIR.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
} 

ll  m , n , a[N][N] , d[N][N] , ans = inf; 



struct node
{
	ll w , u , v;
};

bool operator > (const node&i , const node&j)
{
	return i.w > j.w;
}

void Dijkstra()
{
	priority_queue< node , vector<node> , greater<node> > heap;
   // ll t , r , e;
	for (int i = 1 ; i <= m ; i++) heap.push({1 , i , 1}) , d[i][1] = 1;
	while(heap.size())
	{
		ll du = heap.top().w;
		ll x = heap.top().u;
		ll y = heap.top().v;
	//	cout << du  << ' ';
		heap.pop();
		if(du != d[x][y]) continue;
		for (int i = 0 ; i < 4 ; i++)
		{
		   int p , q , c = 0;
			p = x + row[i];
			q = y + col[i];
			if(p > m || p < 1 || q > n || q < 1) continue;
			if(a[x][y] != a[p][q]) c++;
			if(d[p][q] > d[x][y] + c) d[p][q] = d[x][y] + c , heap.push({d[p][q] , p , q});
		}
	}
	for (int i = 1 ; i <= m ; i++) ans = min(d[i][n] , ans);
	cout << ans;
}
int main()
{
	file();
  cin >> m >> n;
  for (int i = 1 ; i <= m ; i++)
    for (int j = 1 ; j <= n ; j++)
        cin >> a[i][j] , d[i][j] = inf;
  Dijkstra();
  return 0;
    
}

