#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 10001 , MOD = 1e9 + 7 , inf = 1e15 ;
ll ans = inf , n , l , a[N] ;
pi f[3][5001];
void file()
{
 freopen("binpack.inp" , "r" , stdin);
 freopen("binpack.out" , "w" , stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
namespace sub1
{
    const int N=25;
    ll  s1[N], s2[N], cnt1[N], cnt2[N], ans;

    void gen( int x )
    {
        s2[x] = s2[x - 1]; cnt2[x] = cnt2[x - 1];
        if( s1[x - 1] + a[x] > l )
        {
            cnt1[x] = cnt1[x - 1] + 1;
            s1[x] = a[x];
        }
        else
        {
            s1[x] = s1[x - 1] + a[x];
            cnt1[x] = cnt1[x - 1];
        }

        if( x == n ) ans = min(ans, cnt2[n] + cnt1[n] + 2);
        if( x < n ) gen( x + 1);

        s1[x] = s1[x - 1]; cnt1[x] = cnt1[x - 1];
        if( s2[x - 1] + a[x] > l )
        {
            cnt2[x] = cnt2[x - 1] + 1;
            s2[x] = a[x];
        }
        else
        {
            s2[x] = s2[x - 1] + a[x];
            cnt2[x] = cnt2[x - 1];
        }

        if( x == n ) ans = min(ans, cnt2[n] + cnt1[n] + 2);
        if( x < n ) gen(x + 1);
    }

    void solve()
    {
        for(int i = 1 ; i <= n ; i++) cin >> a[i];
        s1[0] = s2[0] = cnt1[0] = cnt2[0] = 0;
        ans = inf;
        gen(1);
        cout << ans ;
    }
}

namespace sub2
{
    const int N = 1e6 + 5;
    int  ll s, a[N];
 
    void solve()
    {
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        cout << s / 100 + ( s % 100 !=0 );
    }
}
int main()
{
	file();
   cin >> l >> n ;
     if (n <= 20)
   {
      sub1::solve();
      return 0;
   }
   if (l == 100)
   {
   	sub2::solve();
   	return 0;
   }
   for (int j = 1 ; j <= l ; j++)
   f[1][j] = f[0][j] = {inf , 0};
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
   f[0][l] = {0 , l};

   for (int i = 0 ; i < n; i++)
   {
   	for (int k = 1 ; k <= l ; k++) f[1 - i % 2][k] = {inf , 0};
       for (int j = 1 ; j <= l ; j++)
         {
        
               if (f[i % 2][j].fi == inf) continue;
               ll res = f[i % 2][j].fi , w2 = f[i % 2][j].se , w1 = j;
    //th1
                if (w2 + a[i + 1] > l) res++ , w2 = a[i + 1] ;
                    else w2 += a[i + 1];
                
                if (res < f[1 - i % 2][j].fi || (res == f[1 - i % 2][j].fi && f[1 - i % 2][j].se > w2)) f[1 - i % 2][j] = {res , w2};
    //th2       
                      res = f[i % 2][j].fi;
                if (w1 + a[i + 1] > l) res++ ,  w1 = a[i + 1] ;
                    else w1 += a[i + 1];
                if (res < f[1 - i % 2][w1].fi || (res == f[1 - i % 2][w1].fi && f[1 - i % 2][w1].se > f[i % 2][j].se)) f[1 - i % 2][w1] = {res , f[i % 2][j].se};
               
         }
   }
   for (int i = 1 ; i <= l ; i++) ans = min(f[n % 2][i].fi , ans);
   cout << ans;
   return 0;
}
