#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2001 , MOD = 1e9 +7 , inf = 1e15;
ll k , n;
string s1 , s2;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub1_2
{
ll Pow[N] , Hash1[N] , Hash2 , ans = 0 , base = 53;
ll get(int x , int y )
{
	return (Hash1[y] - Hash1[x - 1] * Pow[y - x + 1] + MOD * MOD) % MOD;
}
ll check(ll a , ll b , ll c , ll x , ll y , ll z)
{
	return (a * Pow[n - x] + b * Pow[n - x - y] + c) % MOD;
}
void solve()
{
  Pow[0] = 1;
 for (int i = 1 ; i <= n ; i++) Pow[i] = (Pow[i - 1] * base) % MOD ;// cout << i << ' ' << Pow[i] << endl;
  for (int i = 1 ; i <= n ; i++) Hash1[i] = (Hash1[i - 1] * base + s1[i] - 'a' + 1 ) % MOD ;
  for (int i = 1 ; i <= n ; i++) Hash2 = (Hash2 * base + s2[i] - 'a' + 1) % MOD ;
  //cout << Hash2 << endl;
  
  for (int i = 1 ; i <= n - 2 ; i++)
  {
  	for (int j = i + 1 ; j <= n - 1 ; j++)
  	{
  	 ll	x1 = get(1 , i) , x2 = get(i + 1 , j) , x3 = get(j + 1 , n);

  	 ll s1 = i , s2 = j - i , s3 = n - j;
  	 //cout << i << ' ' << j << ' ' << x1 << ' ' << x2 << ' ' << x3 << ' ' << s1 << ' ' << s2 << ' ' << s3 << endl;
  	 if (check(x1 , x2 , x3 , s1 , s2 , s3) == Hash2) {ans ++ ; continue;};
  	 if (check(x1 , x3 , x2 , s1 , s3 , s2) == Hash2) {ans ++ ; continue;};
  	 if (check(x2 , x1 , x3 , s2 , s1 , s3) == Hash2) {ans ++ ; continue;};
  	 if (check(x2 , x3 , x1 , s2 , s3 , s1) == Hash2) {ans ++ ; continue;};
  	 if (check(x3 , x1 , x2 , s3 , s1 , s2) == Hash2) {ans ++ ; continue;};
  	 if (check(x3 , x2 , x1 , s3 , s2 , s1) == Hash2) {ans ++ ; continue;};
	}
  }
  cout << ans ;
}
}
namespace sub3
{
	ll ans = 0 , f[N][N];
  bool check(int x , int y , int z , int a , int b , int c)
  {
  	//cout << x << ' ' << y << ' ' << z << ' ' << a << ' ' << b << ' ' << c << endl;
  	if (f[x][a] >= a  && f[y][b + a] >= b && f[z][a + b + c] >= c) return true;
  	return false;
  }
  void solve()
  {
  	for (int i = 1 ; i <= n ; i++)
  	for (int j = 1 ; j <= n ; j++)
  	{
  	if (abs(s1[i] - s2[j]) <= k) f[i][j] = f[i - 1][j - 1] + 1 ;
  	else f[i][j] = 0;
	   //cout << i << ' ' << j << ' ' << f[i][j] << endl;
     }
  	for (int i = 1 ; i <= n - 2 ; i++)
  	for (int j = i + 1 ; j <= n - 1 ; j++)
  	{
  	  ll	x1 = i , x2 = j , x3 = n , s1 = i , s2 = j - i , s3 = n - j;
  	  	//cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << s1 << ' ' << s2 << ' ' << s3 << endl;
  	 if (check(x1 , x2 , x3 , s1 , s2 , s3)) {ans ++ ; continue;};
  	 if (check(x1 , x3 , x2 , s1 , s3 , s2)) {ans ++ ; continue;};
  	 if (check(x2 , x1 , x3 , s2 , s1 , s3)) {ans ++ ; continue;};
  	 if (check(x2 , x3 , x1 , s2 , s3 , s1)) {ans ++ ; continue;};
  	 if (check(x3 , x1 , x2 , s3 , s1 , s2)) {ans ++ ; continue;};
  	 if (check(x3 , x2 , x1 , s3 , s2 , s1)) {ans ++ ; continue;};
	}
	cout << ans;
  }
}

int main()
{
	cin >> k ;
  cin >> s1 >> s2;
  n = s1.size();
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  if (k == 0) sub1_2::solve();
  else sub3::solve();
}

