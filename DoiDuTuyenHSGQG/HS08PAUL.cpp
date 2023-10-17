#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000005 , MOD = 1e9 +7;
ll d[N] , dp[N] , t , x ;
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
	d[1] = 1 , d[0] = 1 ;
    for(int i = 2; i * i <= 1e7; i++) 
         if(d[i] == 0)  for(int j = i * i; j <= 1e7; j += i)   d[j] = 1; 
}
int main()
{
	file();
    snt();
    for (int i = 1 ; i <= 100 ; i++)
    {
      for (int j = 1 ; j <= 10000 ; j++)
      {
      	ll num = i * i * i * i + j * j;
      	if (num > N) break ;
      	if (d[num] == 0) dp[num] = 1;
	  }
	}
	for (int i = 1 ; i <= N ; i++) dp[i] += dp[i - 1];
    cin >> t ;
    while (t --) cin >> x , cout << dp[x] << '\n';
    return 0;
}

