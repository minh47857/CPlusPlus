#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 57 , MOD = 1e9 +7;
map <ll , ll> f ;
ll n , dom[3][N] , cnt , id[15][15];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll tinh(int n, ll t)
{
    if ( n == 0 ) return 1;
    if ( f.count(t) ) return f[t];
    ll res = 0;
    int x = id[dom[0][n]][dom[1][n]];
    if ( (t & (1LL<<x)) == 0 ) res += tinh(n-1, t|(1LL<<x));
    if ( n >= 2 )
	{
        int x = id[dom[0][n]][dom[0][n-1]];
        int y = id[dom[1][n]][dom[1][n-1]];
        if ( x != y && ((t&(1LL<<x))==0) && ((t&(1LL<<y))==0) )res += tinh(n-2, t|(1LL<<x)|(1LL<<y));
    }
    f[t] = res;
    return res;
}
int main()
{
	file();
     cin >> n ;
     for (int i = 1; i <= n ; i++) cin >> dom[0][i];
     for (int i = 1 ; i <= n ; i++) cin >> dom[1][i];
     cnt = 0;
     for (int i = 0 ; i <= 9 ; i++)
     for (int j = i ; j <= 9 ; j++)
     id[i][j] = id[j][i] = cnt , cnt++;
     cout << tinh(n , 0);
}

