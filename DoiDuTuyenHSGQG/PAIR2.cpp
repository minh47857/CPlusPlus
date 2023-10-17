#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e9;
ll ans = inf , n , k , a[N];
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
	
  cin >> n >> k ;
  for (int i = 1 ; i<= n ; i++) cin >> a[i];
 sort(a + 1 , a + n + 1);
 for (int i = 1 ; i <= k ; i++) ans = min(ans , a[n - k + i] - a[i]);
 cout << ans;
  
}

