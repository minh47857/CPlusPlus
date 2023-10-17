#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll d[N] , a[N] , n , x , res = inf ,m = 0 , prime[N] , f[N];
void sieve()
{
	d[1] = 1;
	for (int i = 2 ; i <= sqrt(x) ; i++)
	if(d[i] == 0) for (int j = i * i ; j <= x ; j += i) d[j] = 1;
}

int main()
{
  	cin >> n >> x;
  	for (int i = 1 ; i <= n ; i++) cin >> a[i];
  	sieve();
  	for (int i = 1 ; i <= n ; i++) if(a[i] > 0 && a[i] <= x && d[a[i]] == 0) prime[++m] = i , f[i] = 1;
  	for (int i = 1 ; i <= n ; i++) f[i] = f[i - 1] + f[i];
  	for (int i = 1 ; i <= n - m + 1 ; i++)
  	{
  		ll ans = m;
  		ans -=(f[i + m - 1] - f[i - 1]);
  	//	cout << ans << ' ';
  		res = min(res , ans);
  	}
  	cout <<res;
}

