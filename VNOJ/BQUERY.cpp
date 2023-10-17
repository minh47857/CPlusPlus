#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 15001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll n , m , q , r[N] , c[N];
int main()
{
  cin >> n >> m >> q;
  for (int i = 1 ; i <= q ; i++) 
  {
  	ll u , v , x , y , t;
  	cin >> t ;
  	if (t == 1) cin >> u >> v , r[u] += v;
	if (t == 2) cin >> u >> v, c[u] += v;
	if (t == 3)
	{
		cin >> u >> v >> x >> y;
		ll maxr = 0, maxc = 0;
		for (int j = u ; j <= x ; j++) maxr = max(maxr , r[j]);
		for (int j = v ; j <= y ; j++) maxc = max(maxc , c[j]);
		cout << maxr + maxc << '\n';
	}
  }
  return 0;
}

