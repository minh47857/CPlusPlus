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
	freopen("NUMMAX.inp" , "r" , stdin);
	freopen("NUMMAX.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll n , b , st[N] , ed[N] , ans = 0 , a[N];
 deque<ll> dq;
int main()
{
	file();
  cin >> n >> b;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  
  for (int i = 1 ; i <= n ; i++)
  {
  	while(  dq.size() && a[i] >= a[dq.back()]) dq.pop_back();
  	if (!dq.size()) st[i] = 1;
  	else st[i] = dq.back() + 1;
  	dq.pb(i);
  }
  dq.clear();
  
  for (int i = n ; i >= 1 ; i--)
  {
  	while(dq.size() && a[i] > a[dq.back()]) dq.pop_back();
  	if (!dq.size()) ed[i] = n;
  	else ed[i] = dq.back() - 1;
  	dq.pb(i);
  }
  
  for (int i = 1 ; i <= n ; i++)
  {
  	if (a[i] == b) ans += ((i - st[i] + 1) * (ed[i] - i + 1));
  }
  cout << ans;
}

