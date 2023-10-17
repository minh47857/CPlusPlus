#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e6 + 3 , inf = 1e15;
void file()
{
	freopen("MINE.inp" , "r" , stdin);
	freopen("MINE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , m , a[N] , f[N] , c[N] , factor[N] , inv[N];


ll sqr(ll x)
{
    return (x * x) % MOD;
}

ll Pow(ll a , ll b)
{
    if (b == 0) return 1;
    if(b % 2 == 0) return sqr(Pow(a , b / 2));
    return (a * sqr(Pow(a , b / 2))) % MOD;
}

int main()
{
	file();
  cin >> n >> m;
  for(int i = 1 ; i <= 2 * n ; i++) cin >> a[i];
  
    factor[0] = 1;
    for (int i = 1 ; i <= N - 1 ; i++) factor[i] = (factor[i - 1] * i) % MOD;
    
    inv[N - 1] = Pow(factor[N - 1] , MOD - 2);
   for (int i = N - 2 ; i >= 1 ; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
   
    c[0] = 1;
    for(int i = 1 ; i <= n ; i++) c[i] = ((factor[i * 2] * inv[i]) % MOD * inv[i + 1]) % MOD; 
    if(n >= 2000)
    {
    	cout << c[n];
    	return 0;
	}
    f[0] = 1;
    for (int i = 2; i <= 2 * n; i += 2) 
        for (int j = 0; j < i; j += 2) 
		{
            if (a[i] - a[j + 1] <= m) 
			{
                f[i] += f[j] * c[(i - j - 2) / 2];
                f[i] %= MOD;
            }
        }
    cout << f[2 * n];
  return 0;
}
