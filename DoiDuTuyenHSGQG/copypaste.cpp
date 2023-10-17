#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 105 , MOD = 1e9 +7;
ll dp[N] , Pow[N] , Hash[N] , len[N][N] , t  , base = 27;
string s;
void file()
{
	freopen("copypaste.inp","r",stdin);
	freopen("copypaste.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get (int x , int y)
{
	return (Hash[y] - Hash[x - 1] * Pow [y - x + 1] + MOD * MOD ) % MOD;
}
void solve ()
{
	vector <ll> clipboard[N];
	string st ;
	cin >> s;
	int n = s.size();
	s = ' ' + s ;
	for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++)
	len[i][j] = 0;
	for (int i = 1 ; i <= n ; i++) Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % MOD ;
	for (int i = n ; i >= 1 ; i--)
	{
		st = s[i] + st ;
		ll k , p[N];
		k = 0 , p[1] = 0;
		string str = ' ' + st;
		for (int j = 2 ; j < str.size() ; j++)
		{
			while (str[k + 1] != str[j] && k > 0) k = p[k];
			if (str[k + 1] == str[j]) k++;
			p[j] = k;
			if (k <= j / 2) 
			{
				len[i][i + j - 1] = k;
				continue ;
			}
			ll f = p[j - 1];
			while (f > 0 && ((f + 1 > j / 2 || str[f + 1] != str[j])))
			{
				 f = p[f];
			}
			len[i][i + j - 1] = f + 1;
		}
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4 ; i <= n ; i++)
	{
		unordered_map <ll , ll > d;
		dp[i] = dp[i - 1] + 1;
		clipboard[i] = clipboard[i - 1];
		for (int j = 1 ; j <= i - 3 ; j++)
		{
			ll num , pos , ans ;
			bool check = false ;
			num = get (j , j + len[j][i] - 1);
			if (len[j][i] == 0 || d[num] == 1 || len[j][i] == 1) continue ;
			d[num] = 1;
		    pos = i - len[j][i] ;
			for (auto x : clipboard[pos])	if (x == num) check = true;
		    ans = dp[pos] + 1;
			if  (check == false)  ans ++;
			if (ans == dp[i]) clipboard[i].pb(num);
			if (ans < dp[i]) clipboard[i].clear() , clipboard[i].pb(num) , dp[i] = ans;
		}
	}
	cout << dp[n] << '\n';
}
int main()
{
	file ();
   cin >> t ;
   	Pow[0] = 1 ;
   for (int i = 1 ; i < N ; i++) Pow[i] = (Pow[i - 1] * base) % MOD;
   while (t --) solve();
   return 0 ;
}

