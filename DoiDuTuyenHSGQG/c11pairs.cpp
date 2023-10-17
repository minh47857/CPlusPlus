#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 5e5 + 5 , MOD = 1e9 +7;
ll n , ri[N] , le[N] , a[N] , ans = 0 , st[4 * N];
vector <ll> num[N];
deque <ll> dq;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void update(int id , int l , int r , int x)
{
	if ( l > x || r < x ) return ;
	if (l == r) 
	{
		st[id]++;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , x);
	update(id * 2 + 1 , mid + 1 , r , x);
	st[id] = st[id * 2] + st[id * 2 + 1];
}
int get(int id , int l , int r , int u , int v)
{
	if (r < u || l > v) return 0;
	if (l >= u && r <= v) return st[id];
	int mid = (l + r) / 2;
	return get(id * 2 , l , mid , u , v) + get(id * 2 + 1 , mid + 1 , r , u , v);
}
void solve()
{
	
	for (int i = n; i >= 1 ; i--)
    {
    	while(dq.size() && a[dq.back()] <= a[i]) dq.pop_back();
    	ri[i] =  (dq.size()) ? dq.back() : (n + 1)  ;
    	dq.push_back(i);
	}
	dq.clear();
	for (int i = 1; i <= n ; i++)
    {
    	while(dq.size() && a[dq.back()] <= a[i]) dq.pop_back();
    	le[i] =  (dq.size()) ? dq.back() : 0  ;
    	dq.push_back(i);
	}
	
  for (int i = 1; i <= n ; i++) num[le[i]].pb(i);
  for (int i = 0 ; i <= n ; i ++)
  {
  	for (auto x : num[i]) update( 1 , 1 , n + 1 , x);
  if (i > 0)	ans += get(1 , 1 , n + 1 , i + 1 , ri[i]);
  }
  cout << ans;
}
int main()
{
	file();
   cin >> n ;
   for (int i = 1 ; i <= n ; i++) cin >> a[i];
   solve();
   return 0 ;
}

