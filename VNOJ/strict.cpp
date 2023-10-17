#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2e5 + 5 , MOD = 1e9 +7 , inf = 1e15;
ll n , a[N] , dem , ans = 1;
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
  cin >> n;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  sort(a + 1 , a + n + 1);
  a[0] = -1 , dem = 0;
  a[n + 1] = -1;
  for (int i = 1 ; i <= n + 1 ; i++)
  {
  	if(a[i] == a[i - 1]) dem++;
  	else 
  	{
  		ans = (ans * (dem + 1)) % MOD;
  		dem = 1;
	}
  }
  cout << ans;
  return 0;
}

