#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , m , a[N][N] , s[N][N] , r = 0 , d = 0 , type , q;
ll calc(int u , int v , int c , int d)
{
	return s[c][d] - s[c][v - 1] - s[u - 1][d] + s[u - 1][v - 1];
}
int main()
{
	file();
  cin >> m >> n;
  for (int i = 1 ; i <= m ; i++)
  for (int j = 1 ; j <= n ; j++) 
  {
  	cin >> a[i][j] ;
  	a[i + m][j] = a[i][j + n] = a[i + m][j + n] = a[i][j];
  }
  memset(s , 0 , sizeof(s));
  for (int i = 1 ; i <= 2 * m ; i++)
  for (int j = 1 ; j <= 2 * n ; j++)
  s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j] ;// cout << i << ' ' << j << ' ' << s[i][j] << ' ' << a[i][j] << '\n';
  cin >> q;
  while(q--)
  {
  	int x ,y , u , v;
  	cin >> type;
  	if (!type)
  	{
  		cin >> x >> y;
  		r = (r + x) % n;
  		d = (d + y) % m;
	}
	else																					             						
	
	{
		cin >> x >> y >> u >> v;
	//	cout << r << ' ' << d << endl;
		cout << calc(x + d , y + r , u + d , v + r) << '\n';
	}
  }
  return 0;
}

