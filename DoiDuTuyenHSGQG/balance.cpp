#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , a[N] , f[N] , dp[N];
//vector< map<ll , ll> > d ;
map < ll , vector<ll> > d;
vector <ll> num;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
   cin >> n ;
   for (int i = 1 ; i <= n ; i++) cin >> a[i];
   d[0].pb(0) , num.pb(0);
   for (int i = 1 ; i <= n ; i++)
   {
   	f[i] = f[i - 1] + a[i];
   	d[f[i]].pb(i);
   	if (d[f[i]].size() == 1) num.pb(f[i]);
   }
   for (auto i : num)
   {
   	for (int j = 0 ; j < d[i].size() ; j++)
   	   {
   		  if (j > 0) dp[d[i][j] + 1] -= j;
   		  dp[d[i][j] + 1] += (d[i].size() - j - 1);
	   }
   }
   for (int i = 1 ; i <= n;  i++) dp[i] = dp[i - 1] + dp[i] , cout << dp[i] << ' ';
   return 0;
}

