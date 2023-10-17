#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll  MOD = 1e9 +7 ;
 ll n , d[30][105] , ans = 0;
 string str;
int main()
{
  cin >> str;
  n = str.size();
  str = ' ' + str;
  for (int i = 1 ; i <= n ; i++)
  { 
  	for (int j = 0 ; j <= 27 ; j++) d[j][i] = d[j][i - 1];
	d[str[i] - 'a'][i]++ , d[str[i] - 'a'][i] %= MOD;
	for (int j = i - 1 ; j >= 3 ; j--)
	for (int k = j - 1 ; k >= 2 ; k--)
	{
		if (str[k] != str[j]) continue;
		ans = (ans + d[str[i] - 'a'][k - 1]) % MOD;
	}
  }
  cout << ans;
}

