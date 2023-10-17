#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 ;
int       r1[10] = { 1 , -1 , 2 , -2 , 1 , - 1 , 2 , -2},
         c1[10] = { 2 , -2 , 1 , -1 , -2 , 2 , -1 , 1 },
         r2[10] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1  },
         c2[10] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1  },
 n  , d1[N][N] , d2[N][N] , ans = INT_MAX;
char s[N][N];
queue <pi> q1 , q2;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool check(int u , int v)
{
	if (u < 1 || v < 1 || u > n || v > n || s[u][v] == '#') return false;
	return true;
}
void Bfs( int r[N] , int c[N] , int d[N][N] , queue <pi> q)
{
	while (q.size())
	{
	pi	x = q.front();
	q.pop();
		for (int i = 0 ; i <= 7 ; i++)
		{
			int x1 = x.fi + r[i];
			int y1 = x.se + c[i];
			if (!check(x1 , y1) || d[x1][y1] !=  -1) continue ;
			q.push({x1 , y1});
			d[x1][y1] = d[x.fi][x.se] + 1;
		}
	}
}
int main()
{
  cin >> n ;
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= n ; j++) 
  cin >> s[i][j];
  for (int i = 1 ; i <= n ; i ++)
  {
  	for (int j = 1 ; j <= n ; j++)
  	{
  		d1[i][j] = d2[i][j] = -1;
  		if (s[i][j] == 'M') q1.push({i , j}) , d1[i][j] = 0;
  		if (s[i][j] == 'T') q2.push({i , j}) , d2[i][j] = 0;
	}
  }
  Bfs(r1 , c1 , d1 , q1);
  Bfs(r2 , c2 , d2 , q2);
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= n ; j++)
  {
  	if(d1[i][j] == -1 || d2[i][j] == -1 || abs(d1[i][j] - d2[i][j]) % 2 == 1) continue ;
  	ans = min (max(d1[i][j] , d2[i][j]) , ans);
  }
  if (ans != INT_MAX) cout << ans;
  else cout << -1 ;
  return 0;
}

