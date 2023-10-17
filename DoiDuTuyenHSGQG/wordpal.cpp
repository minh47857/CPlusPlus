#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 51, MOD = 1e9 + 7 , inf = 1e15;
string s[N] ;
ll n , a[N] , g[N][N][21][3] , c[N] , f[N][21][3] , res = inf , d[N][21][3];
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool check (ll x , ll y , ll l1 , ll r1 , ll l2 , ll r2)
{
    string str1 , str2;
    for (ll i = l1 ; i <= r1 ; i++) str1 += (s[x])[i];
    for (ll i = r2 ; i >= l2 ; i--) str2 += (s[y])[i];
    if (str1.size() > str2.size()) swap(str1 , str2);
    for (ll i = 0 ; i < str1.size() ; i++) if (str1[i] != str2[i]) return false;
    return true;
}
bool palin(ll x , ll y , ll z)
{
    string str1 , str2;
    ll l , r;
      r = (z == 0) ? a[x] : y;
    l = (z == 0) ? (a[x] - y + 1) : 1;
    for (ll i = r ; i >= l ; i--) str1 += (s[x][i]);
    for (ll i = l ; i <= r ; i++) str2 += (s[x][i]);
    if (str1 == str2) return true;
    return false;
}
ll calc(ll id , ll r , ll w)
{
     d[id][r][w] ++;
    if (f[id][r][w] != -1) return f[id][r][w];
    if (d[id][r][w] > 3) return inf;
    
    if (r == 1 || r == 0 || palin(id , r , w)) 
    {
        //cout << id << ' ' << r << ' ' << w << ' ' << 0 << endl;
        return 0;
    }
    ll cnt = inf;
    for (ll i = 1 ; i <= n ; i++)
    {
      //  cout << id << ' ' << i << ' ' << r << ' ' << w << ' '<< g[id][i][r][w] << endl;
        if (g[id][i][r][w] == 0) continue;
        ll ii , rr , ww , val;
       ii = (r <= a[i]) ? i : id;
       rr = abs(r - a[i]);
       if (ii != id) ww = 1 - w;
       else ww = w;
       val = calc(ii , rr , ww);
       cnt = min(cnt , val + c[i]);
    }
    f[id][r][w] = cnt;
   // cout << id << ' ' << r << ' ' << w << ' ' << cnt << endl;
    return cnt;
}
int main()
{
    file();
   cin >> n ;
   for (int i = 1 ; i <= n ; i++)    
   {
         cin >> s[i] >> c[i];
         a[i] = s[i].size();
         s[i] = ' ' + s[i];
   }
   memset(f , -1 , sizeof (f));
   for (int i = 1 ; i <= n ; i++)
   {
       for (int k = 1 ; k <= s[i].size() ; k++)
       {
           for (int j = 1 ; j <= n ; j++)
           {
             for (int l = 0 ; l <= 1 ; l++)
             {
               if (l == 0 && check (i , j ,a[i] - k + 1, a[i] , 1 , a[j])) g[i][j][k][l] = 1;
               if (l == 1 && check(j , i , 1 , a[j] , 1 , k) ) g[i][j][k][l] = 1;
              // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << g[i][j][k][l] << '\n';
             }    
        }
    }
   }
  // cout << calc(1 , 2 , 0);
  for (int i = 1 ; i <= n ; i++) 	res = min(res , calc(i , a[i] , 0) + c[i]) ;
  
 //  cout << palin(2 , a[2] , 0);
 if (res == inf) cout << -1;
 else  cout << res;
   return 0;
  
}




