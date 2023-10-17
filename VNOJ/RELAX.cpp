#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 3000001 , MOD = 1e9 +7 , inf = 1e15;
ll Bit , n , a[N] , d[N][3] , ans = 0;
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
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  Bit = 0;
  d[Bit][0] = 1;
  for (int i = 1 ; i <= n ; i++)
  {
  	Bit ^= a[i];
  	ans += d[Bit][i % 2];
  	d[Bit][i % 2]++;
  }
  cout << ans;
  return 0;
}

