#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , a[N] , f[N] , g[N] , ans = -inf;
multiset<ll> q , p;
int main()
{
	file();
  cin >> n ;
  for (int i = 1 ; i <= 3 * n ; i++) cin >> a[i];
  for (int i = 1 ; i <= n ; i++) 
  {
  	f[i] = f[i - 1] + a[i];
  	q.insert(a[i]);
  	int j = 3 * n - i + 1;
  	g[j] = g[j + 1] + a[j];
  	p.insert(a[j]);
  }
  for (int i = n + 1 ; i <= 2 * n ; i++)
  {
  	f[i] = f[i - 1] + a[i];
  	q.insert(a[i]);
  	f[i] -= (*q.cbegin());
  	q.erase(q.cbegin());
  	int j = 3 * n - i + 1;
  	
  	g[j] = g[j + 1] + a[j];
  	p.insert(a[j]);
  	g[j] -= (*p.rbegin());
  	p.erase(p.find(*p.rbegin()));
  //	cout <<i << ' ' << j << ' ' << f[i] << ' ' <<g[j] << endl;
  }
  for (int i = n ; i <= 2 * n ; i++) ans = max(ans , f[i] - g[i + 1]);
  cout << ans ;
  return 0;
}
