#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10001 , MOD = 1e9 +7 , inf = 1e15 , M = 101;
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 string k;
 ll d , dem = 0 , f[N][M][3][3] , a[N];
ll calc(int i , int du , int ok , int ok2)
{
//    cout << i << ' ' << du << ' ' << ok << endl;
    if (i == 0)
    {
        if (du == 0 && ok2) return 1;
        else return 0;
    }
    if (f[i][du][ok][ok2] != -1) return f[i][du][ok][ok2];
    ll Max , cnt = 0;
    if (ok) Max = 9;
    else Max = a[i] ; 
    for (int t = 0 ; t <= Max ; t++) 
    {
    //    cout << t << endl;
        cnt = (cnt + calc(i - 1 , (du + t) % d , ok | (t != a[i]) , ok2 | (t != 0))) % MOD;
    }
//    cout << i << ' ' << du << ' ' << ok << ' ' << cnt << endl;
    f[i][du][ok][ok2] = cnt;
    return cnt;
}

int main()
{
    file();
  cin >> k >> d;
  for (int i = k.size() - 1 ; i >= 0 ; i--) a[++dem] = (k[i] - '0') ;
  memset(f , -1 , sizeof(f));
  //cout << 0 | (0 == 3)
  cout << calc(dem , 0 , 0 , 0);
  return 0;
}

