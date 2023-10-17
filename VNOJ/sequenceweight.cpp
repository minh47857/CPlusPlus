#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll a[N] , n , ans , t;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin >> t;
	while (t--)
	{
		cin >> n;
		unordered_map<ll , ll> d;
		ans = 0;
     for (int i = 1 ; i <= n ; i++) cin >> a[i];
      for (int i = 1 ; i <= n ; i++)
       {
  	     ans = ans + d[a[i]] * (n - i + 1);
  	    d[a[i]] += i;
      }
     cout << ans << '\n';
    }
  
}

