#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 struct node
 {
 	ll val , lazy;
 } st[4 * N];
 ll ans = inf  , a[N] , b[N] , c[N] , n , m;
void down (int id)
{
  ll t = st[id].lazy;
  st[id * 2].val += t;
  st[id * 2 + 1].val += t;
  st[id * 2].lazy += t;
  st[id * 2 + 1].lazy += t;
  st[id].lazy = 0;
}

void update(int id ,int l , int r , int u , int v , ll value)
 {
 	if (u > r || v < l) return;
 	if(l >= u && r <= v) 
 	{
 		st[id].val += value;
 		st[id].lazy += value;
 		return;
	}
	down(id);
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v , value);
	update(id * 2 + 1 , mid + 1 , r , u , v , value);
	st[id].val = max(st[id * 2].val , st[id * 2 + 1].val);
 }
 
 
int main()
{
	file();
  cin >> n >> m;
  for (int i = 1 ; i <= m ; i++) cin >> a[i] >> b[i] >> c[i] , update(1 , 1 , n , a[i] , b[i] , c[i]);
  for (int i = 1 ; i <= m ; i++)
  {
  	update(1 , 1 , n , a[i] , b[i] , -c[i]);
  	ans = min(st[1].val , ans);
  	update(1 , 1 , n , a[i] , b[i] , c[i]);
  }
  cout << ans;
  return 0;
}

