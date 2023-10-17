#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7;
ll m , n , r , c , a[N][N] , s[N][N];
vector <ll> num , v;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll tinh (int u , int v)
{
	return s[u][v] - s[u - r][v] - s[u][v - c] + s[u - r][v - c];
}
bool check(ll x)
{
	for (int i = 1 ; i <= m ; i++)
	for (int j = 1 ; j <= n ; j++)
	s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] <= x) ;
	
	for (int i = r ; i <= m ; i++)
	for (int j = c ; j <= n ; j++)
	if (tinh(i , j) >= (r * c)/2 + 1) return true;
	
	return false;
}
int main()
{
  cin >> m >> n >> r >> c;
  for (int i = 1 ; i <= m ; i++)
  for (int j = 1 ; j <= n ; j++)
		cin >> a[i][j] , v.pb(a[i][j]);
   sort (v.begin(), v.end());
   num.pb(v[0]);
   for (int i = 1 ; i < v.size() ; i++) if (v[i] != v[i - 1]) num.pb(v[i]);
   ll d = 0 , c = num.size() - 1 , kq , g;
   while (d <= c)
   {
   	 g = (d + c) / 2;
   	 if (check(num[g]))
   	 {
   	 	kq = num[g];
   	 	c = g - 1;
	 }
	 else d = g + 1 ;
   }
  cout << kq;
}

