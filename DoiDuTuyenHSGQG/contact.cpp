#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7 , inf = 1e15;
ll dem = 1 , n , m , d[20][N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int root(int v , int k) 
{
    if (d[k][v] < 0) return v;
    d[k][v] = root(d[k][v] , k);
    return d[k][v];
}
void merge(int x, int y , int k) 
{
    if ((x = root(x , k)) == (y = root(y , k)))  return ;
    
    if (d[k][y] < d[k][x])   swap(x, y);
    d[k][x] += d[k][y];
    d[k][y] = x;
}
int main()
{
  cin >> n >> m;
  memset(d , -1 , sizeof(d));
  for (int i = 1 ; i <= m ; i++)
  {
  	ll u , v , l , off = 0;
  	cin >> u >> v >> l;
  	for (int k = 18 ; k >= 0 ; k--)
  	{
  		if (l >= (1 << k))
  		{
  			merge(u + off, v + off , k);
  			off += (1 << k);
  			l -= (1 << k);
	    }
    }
  }
  for (int k = 18 ; k >= 1 ; k--)
  {
  	for (int i = 1 ; i <= n ; i++)
  	{
  		ll r = root(i , k);
  		merge(r , i , k - 1);
  		merge(r + (1 << (k - 1)) , i + (1 << (k - 1)) , k - 1);
	}
  }
  for (int i = 1 ; i <= n ; i++) if (root(i , 0) == i) dem = (dem * 2) % MOD;
  cout << dem ;
  return 0;
  
}

