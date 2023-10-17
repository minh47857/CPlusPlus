#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 20 , MOD = 1e9 +7,
       row[5] = {0 , -1 , 0 , 1} ,
       col[5] = {-1 , 0 , 1 , 0} ;
   char h[5] , path[10001];
bool check = false ;     
ll n , m , q , p , k , l , d[N][N][N][N] , cnt = 0 ,a[N][N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool checkk(int u , int v)
{
	if (u < 0 || u >= n || v < 0 || v >= m  || a[u][v] == 1) return false;
	return true;
}
void Dfs(int x , int y , int u , int v)
{
	if (d[x][y][u][v] == 1 || check == true) return ;
	d[x][y][u][v] = 1;
	if (x == 0 && y == 0 && u == 0 && v == 0) 
	{
		check = true;
		cout << cnt << endl;
		for (int i = 1 ; i <= cnt ; i++) cout << path[i];
		return ;
	}
	for (int i = 0 ; i <= 3 ; i++)
	{
	  int x1 = x + row[i];
	  int y1 = y + col[i];
	  int u1 = u + row[i];
	  int v1 = v + col[i];
	  if (!checkk(x1 , y1)) x1 = x , y1 = y;
	  if (!checkk(u1 , v1)) u1 = u , v1 = v;
	  cnt ++;
	  path[cnt] = h[i];
	  Dfs(x1 , y1 , u1 , v1);
	  cnt --;
	}
}
int main()
{
	file();
   cin >> n >> m >> p >> q >> k >> l;
   for (int i = 0 ; i < n ; i++)
   for (int j = 0 ; j < m ; j++)
   cin >> a[i][j];
   h[0] = 'L' , h[1] = 'U' , h[2] = 'R' , h[3] = 'D';
   Dfs(p , q , k , l);
   return 0;
}

