#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1500 , MOD = 1e9 +7 , inf = 1e17;
int d[N] , t ;
ll n , m , f[20][2][2][N] , a[20] , b[20];
void file()
{
	//freopen("d13clear.inp" , "r" , stdin);
//	freopen("d13clear.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int dfs(int u)
{
	if (d[u] != -1) return d[u];
	d[u] = 0;
	int s = 0 , v = u;
	while (v)  s += (v % 10) * (v % 10) , v /= 10; 
	d[u] = dfs(s);
	return d[u];
}
ll calc(int i , int oka , int okb , int sum)
{
	if (i > 17)	return d[sum];
	if (f[i][oka][okb][sum] != -1) return f[i][oka][okb][sum];
	
	ll cnt = 0 , Min , Max;
	if (oka) Min = 0 ; else Min = a[i];
	if (okb) Max = 9 ; else Max = b[i];
	
    
	for (int t = Min ; t <= Max ; t++)	cnt += calc(i + 1 , oka | (t > a[i]) , okb | (t < b[i]) , sum + t * t);
	
	f[i][oka][okb][sum] = cnt;
	return cnt;
}
bool check (ll x)
{
	ll u = n , v = x;
	for (int i = 17 ; i >= 0 ; i-- , u /= 10) a[i] = u % 10 ;
	for (int i = 17 ; i >= 0 ; i-- , v /= 10) b[i] = v % 10 ;
	memset(f , -1 , sizeof(f));
	ll res = calc(0 , 0 , 0 , 0 ) ;
	if (res >= m) return true;
	return false;
}
int main()
{
	file();
  memset(d , - 1 , sizeof(d));
  d[1] = 1;
  for (int i = 1458 ; i >= 2 ; i--) d[i] = dfs(i);
  cin >> t;
 while(t --)
  {
  	cin >> n >> m;
  	n++;
  	ll d = n , c = inf , kq , g;
  	while (d <= c)
  	{
  		g = (d + c) / 2;
  		if (check(g)) kq = g , c = g - 1;
  		else d = g + 1;
	}
	cout << kq << '\n';
  }
}

