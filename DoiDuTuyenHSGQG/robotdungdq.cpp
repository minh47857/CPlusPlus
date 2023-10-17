#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 5e2 + 5 , MOD = 1e9 +7 , inf = 1e15 , M = 5e3 + 5;
void file()
{
   // freopen("robotdungdq.inp" , "r" , stdin);
   // freopen("robotdungdq.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n , oldm , m , f[M][N][10] , a[N][10]  , ans = 0 , k ,res = 0 , b[101][105][105] , ok[105][105];
string s[N] , str;

ll Bit(ll x , ll P)
{
    return (x >> P) & 1;
}

void solve()
{
  for(int i = 1 ; i <= n ; i++)
   {
    for(int j = 1 ; j <= m ; j++)  
       {
           int l = (j + 59) / 60 ;
           int pos = (j - 1) / 60 + 1;
          ll val =  1LL << (l * 60 - j);
           if(s[i][j] == '.') a[i][pos] +=  val, f[0][i][pos] += val;
       }
   }
    
  for(int d = 1 ; d <= k ; d++)
  {
      for(int i = 1 ; i <= n ; i++)
      {
          for(int j = 1 ; j <= m / 60 ; j++)
          {
              ll tmp;
      // N        
            if ((str[d] == 'N' || str[d] == '?') && i != n)
             {
                tmp = f[d - 1][i + 1][j] & a[i][j];
                f[d][i][j] |= tmp;
             }
    // S            
            if ((str[d] == 'S' || str[d] == '?') && i != 1)
             {
                tmp = f[d - 1][i - 1][j] & a[i][j];
                f[d][i][j] |= tmp;
             }
    // W        
            if ((str[d] == 'W' || str[d] == '?') )
             {
                tmp = (f[d - 1][i][j] - Bit(f[d - 1][i][j] , 59) * (1LL << 59)) * 2 + Bit(f[d - 1][i][j + 1] , 59);
                tmp = tmp & a[i][j];
                f[d][i][j] |= tmp;
             }
    // E        
            if ((str[d] == 'E' || str[d] == '?') )
             {
                tmp = f[d - 1][i][j] / 2 + ( (f[d - 1][i][j - 1] % 2 == 1) ? (1LL << 59) : 0 );
                tmp = tmp & a[i][j];
                f[d][i][j] |= tmp;
             }
        }
       
    }
  }
  
  for(int i = 1 ; i <= n ; i++)
     for(int j = 1 ; j <= m / 60 ; j++)
       ans +=  __builtin_popcountll(f[k][i][j]) ;
  cout << ans;
   
}
void sub1()
{
    m = oldm;
    for(int i = 1 ; i <= n ; i++)
       for(int j = 1 ; j <= m ; j++)
         ok[i][j] = b[0][i][j] = (s[i][j] == '.');
    for(int d = 1 ; d <= k ; d++)
    {
      for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            {
      // N        
            if ((str[d] == 'N' || str[d] == '?') && i != n)
             {
                b[d][i][j] |= (b[d - 1][i + 1][j] & ok[i][j]);
             }
    // S            
            if ((str[d] == 'S' || str[d] == '?') && i != 1)
             {
                b[d][i][j] |= (b[d - 1][i - 1][j] & ok[i][j]);
             }
    // W        
            if ((str[d] == 'W' || str[d] == '?') )
             {
                b[d][i][j] |= (b[d - 1][i][j + 1] & ok[i][j]);
             }
    // E        
            if ((str[d] == 'E' || str[d] == '?') )
             {
                b[d][i][j] |= (b[d - 1][i][j - 1] & ok[i][j]);
             }
            }
    }
    for(int i = 1 ; i <= n ; i++)
      for(int j = 1 ; j <= m; j++)
       res += b[k][i][j] ;
    cout << res ;
}
int main()
{
    file();
  cin >> n >> oldm >> k;
  for(int i = 1 ; i <= n ; i++) cin >> s[i] , s[i] = ' '+ s[i];
  cin >> str;
  str = ' ' + str;
 // sub1();
  m = (59 + oldm) /60 * 60;
  for(int i = 1 ; i <= n ; i++)
     for(int j = oldm + 1 ; j <= m ; j++)
        s[i] = s[i] + '#';
   solve();
   return 0;
}

