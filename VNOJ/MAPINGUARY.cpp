#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 200001 , MOD = 1e9 +7 , inf = 1e15;
ll n , w1[N][4] , w2[N] , Max[N] , s[N] , dp[N][15] , ans = 0;
void file()
{
	//freopen("MAPINGUARY.inp" , "r" , stdin);
//	freopen("MAPINGUARY.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi calcmax(ll a , ll b , ll c )
 {
	vector<ll> q;
	q.pb(a) , q.pb(b) , q.pb(c) ;
	sort(q.begin() , q.end());
	return make_pair(q[2] , q[1]);
 }
 int du (int u)
 {
 	if (u  != 0) return u;
 	return 10;
 }
int main()
{
	file();
  cin >> n  ;
  for (int i = 1 ; i <= n ; i++) 
  {
  	int k ; vector <ll> v;
  	cin >> k;
  	while (k--) 
  	{
  		ll x , y;
  		cin >> x >> y;
  		if (x == 2) w2[i] = max(w2[i] , y);
  	    if (x == 1)	v.pb(y);
  	    Max[i] = max(y , Max[i]);
	}
	sort(v.begin() , v.end() , greater <ll>());
	for (int j = 0 ; j < min(int(v.size()) , 3) ; j++) w1[i][j + 1] =  v[j] , s[i]++;
	//cout << w2[i] << ' ' << w1[i][1] << ' ' << s[i] << ' ' << Max[i] << endl;
  }
  memset(dp , - 1 , sizeof(dp));
  dp[0][0] = 0;
 for (int i = 0 ; i < n ; i++)
 {
 	for (int j = 0 ; j <= 10 ; j++)
 	{
 	  if (dp[i][j] == -1 ) continue;	
 	  //cout << i << ' ' << j << ' ' << dp[i][j] << ' ';;
 	  dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
 	  dp[i + 1][du((j + 1) % 10)] = max(dp[i][j] + ((j == 9) ? ( 2 * Max[i + 1]) : Max[i + 1]) , dp[i + 1][du((j + 1) % 10)]) ;// cout << du((j + 1) % 10) << ' ' << dp[i + 1][du((j + 1) % 10)] << "|";
 	if (s[i + 1] == 3)  dp[i + 1][du((j + 3) % 10)] = max( dp[i + 1][du((j + 3) % 10)] ,  dp[i][j] + w1[i + 1][3] + w1[i + 1][2] + ((j >= 7 && j != 10) ? (2 * w1[i + 1][1] ) : w1[i + 1][1] )) ; //cout <<  du((j + 3) % 10) << ' ' << ' ' << dp[i + 1][du((j + 3) % 10)] << "|";
 	
 	if (s[i + 1] + w2[i + 1] >= 2 && s[i + 1] >= 1) 
	 {
	 //	cout << dp[i + 1][du((j + 2) % 10)] << ' ' << w1[i + 1][2] << ' ' << w1[i + 1][1] << ' ' << w2[i + 1] << ' ';
	 	pi res = calcmax(w1[i + 1][2] , w1[i + 1][1] , w2[i + 1]);
	 	dp[i + 1][du((j + 2) % 10)] = max(dp[i + 1][du((j + 2) % 10)] , dp[i][j] + res.se + ((j >= 8 && j != 10) ? (2 * res.fi) : res.fi));
	 	//cout << du((j + 2) % 10) << ' ' << dp[i + 1][du((j + 2) % 10)] << "|";
	 }
//	 cout << '\n';
	}
 }
 for (int i = 0 ; i <= 10 ; i++) ans = max(ans , dp[n][i]);
 cout << ans ;
 return 0;
}
