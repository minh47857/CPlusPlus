#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 15 , MOD = 1e9 +7;
ll n , k;
ll f[105][1 << N] , ans = 0;
void file()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int Bit (int x ,int m)
{
    return ( x >> m) & 1;
}
int main()
{
   cin >> n >> k;
   f[0][ (1 << (k + 1)) - 1] = 1;
   for (int i = 0 ; i < n ; i++)
   {
         for (int mask = 0 ; mask < (1 << (2 * k + 1)) ; mask++)
            {
                if (f[i][mask] == 0) continue;
              int  n_mask = mask >> 1 ;
                  for (int j = 0 ; j < 2 * k + 1 ; j++)
                       {
                           int num = i - k + 1 +j;
                           if (num < 1 || num > n) continue;
                          if (!Bit(n_mask , j))
                          {
                              int newmask = n_mask | ( 1 << j);
                              f[i + 1][newmask] = (f[i + 1][newmask] + f[i][mask]) % MOD;
                    }
                  }
         }
   }
   for (int i = 0 ; i < (1 << (2 * k + 1)) ; i ++) ans += f[n][i] ;
  cout << ans %MOD ;
    return 0;
}

