#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 505 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll f[N][N] , fa[N] , inv[N] ;
string s;
ll Pow(int a, int b)
{
    if ( b == 1 ) return a;
    ll res = Pow(a, b/2);
    if ( b % 2 ) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

ll C(int n, int k){
    if ( k == 0 || k == n) return 1;
    if ( k > n ) return 0;
    return fa[n] * inv[n-k] % MOD * inv[k] % MOD;
}

ll calc(int l, int r)
{
    if ( ( r - l + 1 ) % 2 ) return 0;
    if ( f[l][r] != -1 ) return f[l][r];
    if ( l > r ) return 1;

    ll cnt = 0;
    for (int mid = l + 1; mid <= r; mid ++)
        if ( s[l] == s[mid] )
		{
            int l1 = (mid - l + 1) / 2, l2 = (r - l + 1) / 2;
           cnt = ( cnt + C(l2, l1) * calc(l + 1, mid - 1) % MOD * calc(mid + 1, r) % MOD ) % MOD;
        }

    f[l][r] = cnt;
    return cnt;
}
int main()
{
	file();
  cin >> s;
  s = ' ' + s;
  memset(f , -1 , sizeof(f));
  fa[0] = 1;
  for (int i = 1 ; i < N ; i++) fa[i] = fa[i - 1] * i % MOD;
  inv[N-1] = Pow(fa[N-1] , MOD-2);
  for (int i = N - 2; i >= 1; i --)
        inv[i] = inv[i+1] * (i+1) % MOD;
  cout << calc(1 , s.size() - 1);
} 

