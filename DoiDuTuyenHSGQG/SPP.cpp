#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7;
ll a , b , dp[N] , d[N] , t;
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void snt() 
{

    for (int i = 1 ; i <= N / 2 ; i++)
    for (int j = i * 2 ; j <= N ; j += i) d[j] += i;

    for (int i = 1 ; i <= N; i++) 
    {
        dp[i] = dp[i - 1];
       if (d[i] > i) dp[i] ++;
    }
}
int main()
{
    file();
    snt();
   cin >> a >> b;
  cout << dp[b] - dp[a - 1];
  return 0;
}
