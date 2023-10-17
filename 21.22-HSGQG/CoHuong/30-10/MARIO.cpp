#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 705 , inf = 1e15 ,
      row[5] = {0 , 0 , 1 , -1 , 0} ,
      col[5] = {0 , 1 , 0 , 0 , -1} ;
void file()
{
	freopen("MARIO.inp" , "r" , stdin);
	freopen("MARIO.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
} 

ll  m , n , a[N][N] , d[N][N] , c[N][N][5]; 



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
   heap.push({0 , 1 , 1}) , d[1][1] = 0;
	while(heap.size())
	{
		ll du = heap.top().w;
		ll x = heap.top().u;
		ll y = heap.top().v;
	//	cout << du  << ' ' << x << ' ' << y << '\n';
		heap.pop();
		if(du != d[x][y]) continue;
		for (int i = 1 ; i <= 4 ; i++)
		{
		   ll p , q , w = 0;
			p = x + row[i];
			q = y + col[i];
			w = c[x][y][i];
			if(p > n || p < 1 || q > m || q < 1) continue;
		//	cout << w << ' ' << p << ' ' << q << ' ' << i  << endl;
			if(d[p][q] > d[x][y] + w) d[p][q] = d[x][y] + w , heap.push({d[p][q] , p , q});
		}
	//	cout << endl;
	}
	cout << d[n][m];
}
int main()
{
	file();
  cin >> n >> m;
  for (int i = 1 ; i <= n ; i++)
    for (int j = 1 ; j <= m ; j++)
         d[i][j] = inf;
   for(int i = 1 ; i <= n ; i++)
     for(int j = 1 ; j < m ; j++)
        cin >> c[i][j][1] , c[i][j + 1][4] = c[i][j][1];
        
    for(int i = 1 ; i < n ; i++)
       for(int j = 1 ; j <= m ; j++)
        cin >> c[i][j][2] , c[i + 1][j][3] = c[i][j][2]; 
  Dijkstra();
  return 0;
    
}

