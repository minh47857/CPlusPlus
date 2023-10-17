#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1005  , inf = 1e9 ,
        row[5] = {1 , 0 , -1 , 0},
        col[5] = {0 , 1 , 0 , -1};
void file()
{
	freopen("MOHINH.inp" , "r" , stdin);
	freopen("MOHINH.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node
{
	ll c , fi , se;
};

bool operator > (const node&a , const node&b)
{
	return a.c > b.c;
}

ll n , m , a[N][N] , b[N][N] , ans = 0;
priority_queue< node , vector<node> , greater<node> > q;
int main()
{
	file();
  cin >> n >> m;
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= m ; j++)
  cin >> a[i][j] , b[i][j] = inf;
  
  for (int i = 1 ; i <= n ; i++) q.push({a[i][1] , i , 1}) , q.push({a[i][m] , i , m}) , b[i][1] = a[i][1] , b[i][m] = a[i][m];
  for (int i = 2 ; i < m ; i++) q.push({a[1][i] , 1 , i}) , q.push({a[n][i] , n , i}) , b[1][i] = a[1][i] , b[n][i] = a[n][i];
  
  while(!q.empty())
  {
  	ll u = q.top().fi , v = q.top().se , w = q.top().c ;
  	q.pop();
  //	cout << u << ' ' << v << ' ' << w << '\n';
  	 if(b[u][v] != w) continue;
  	for (int i = 0 ; i < 4 ; i++)
  	{
  	 ll	x = u + row[i] , y = v + col[i] ;
  	    if(x < 1 || y < 1 || x > n || y > m) continue;
		if(b[x][y] > max(b[u][v] , a[x][y]))
		{
			b[x][y] = max(b[u][v] , a[x][y]);
			q.push({b[x][y] , x , y});
		}	
	}
  }
  for (int i = 1 ; i <= n ; i++)
     for (int j = 1 ; j <= m ; j++)
         ans = ans + b[i][j] - a[i][j];
  cout << ans;
  return 0;
}

