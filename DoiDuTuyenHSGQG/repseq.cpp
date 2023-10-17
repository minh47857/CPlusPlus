#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 5e5 + 5 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 struct node 
 {
 	ll val , lazy;
 } ;
 node st[4 * N];
 ll n , t , a[N] , d[N] , near[N] ;
 pi ans , res;
void down(int id)
{
	ll t = st[id].lazy; 
	st[id * 2].lazy += t;
	st[id * 2 + 1].lazy += t;
	st[id * 2].val += t;
	st[id * 2 + 1].val += t;
	st[id].lazy = 0;
}

void update(int id  , int l , int r , int u , int v , int value)
{

	if (u > r || v < l) return;
	if (u <= l && r <= v) 
	{
		st[id].lazy += value; 
		st[id].val += value;
		return ;
	}
	down(id);
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v , value);
	update(id * 2 + 1 , mid + 1 , r , u , v , value);
	st[id].val = min(st[id * 2].val , st[id * 2 + 1].val);
}

pi minimum(pi x , pi y)
{
	if (x.fi > y.fi) return y;
	if (x.fi == y.fi & x.se < y.se) return y;
	return x;
}

pi get(int id , int l , int r , int pos)
{
	if (l > pos ) return {inf , 0} ;
		
	if (l == r)	return {st[id].val , pos - l + 1};
	
		int mid = (l + r) / 2;
		down(id);
		
	if (r <= pos)
	{
		if (st[id * 2].val <= st[id * 2 + 1].val) return get(id * 2 , l , mid , pos);
		else return get(id * 2 + 1 , mid + 1 , r , pos);
	}

	return minimum(get(id * 2 , l , mid , pos ) ,  get(id * 2 + 1 , mid + 1 , r , pos));
	 
}

void solve()
{
  for (int i = 1 ; i <= n ; i++) cin >> a[i] , d[a[i]] = near[i] = 0;
  for (int i = 1 ; i <= 4 * n ; i++) st[i].lazy = 0 , st[i].val = 0;
   res = {inf , 1} ;
  
  for (int i = 1 ; i <= n ; i++)
  {
    update(1 , 1 , n , d[a[i]] + 1 , i , 1);
    if (d[a[i]] != 0)	update(1 , 1 , n , near[d[a[i]]] + 1 , d[a[i]] , -1 ) ;
    near[i] = d[a[i]];
  	res = minimum(res , get(1 , 1 , n , i));
  	d[a[i]] = i;
  }
  cout << res.fi << ' ' << res.se << '\n';
}
int main()
{
	file();
	while(cin >> n) solve();
	return 0;
}

