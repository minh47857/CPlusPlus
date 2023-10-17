#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 ;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , x , a[N] , m ;
ll ans = 0;
int main()
{
	file();
  cin >> n >> x;
  m = n;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  for (int i = 1 ; i <= n ; i++)
  {
  	while (m != 0 && a[i] + a[m] > x) m--;
  	ans += min(m , i - 1);
  }
  cout << ans ;
}
