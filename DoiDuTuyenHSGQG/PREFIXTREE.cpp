#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , k , a[N] , res = 0 , bit[N] , du;
map <string , int> d;
vector <int> ans;
string st , s[N] , str;
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll sqr (ll x)
{
    return (x * x) % MOD;
}
ll poww(ll x, ll y)
{
    if(y == 0) return 1;
    ll res = poww(x , y / 2);
    if(y % 2) return (((res * res) % MOD) * x) % MOD;
    return (res * res) % MOD;
}
ll tinh(int x , int k)
{
    return (a[x] * du) % MOD;
}
void update(int u , int v)
{
    for (int i = u ; i <= n ; i += (i & (- i))) bit[i] -= v;
}
ll get (int u)
{
    ll ans = 0 ;
    for (int i = u ; i >= 1 ; i -= (i & (- i))) ans += bit[i];
    return ans;
}
int main()
{
    file();
   cin >> n >> k;
   for (int i = 1 ; i <= n ; i++) cin >> s[i] , update(i , -1);
   sort (s + 1 , s + n + 1);
   for (int i = 1 ; i <= n ;i++) d[s[i]] = i ;
   cin >> st ;
   st = ' ' + st ;
    for (int i = 1 ; i < st.size() ; ++i)
    {
        str = str + st[i];
        if (d[str] != 0) ans.pb(d[str]) , str = "";
    }
    a[1] = 1;
    a[0] = 1;
    for (int i = 2 ; i < N ; i++) a[i] = (a[i - 1] * i) % MOD;
     du = poww( a[n - k] , MOD - 2);

   for (int i = 0 ; i < ans.size() ;i++)
   {
       ll u = get(ans[i] - 1);
       ll x = n - i - 1;
       ll y = ans.size() - i - 1;
        res = ( res + u * tinh(x , y)  ) % MOD;
        update(ans[i] , 1);
   }
   cout << (res + 1) % MOD;
}

