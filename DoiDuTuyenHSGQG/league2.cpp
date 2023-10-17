#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e6 + 5;
ll ans[N], st[4 * N], n, m , q, res, num, qr = 1, x[N];
pi a[N], query[N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void update( ll id, ll l , ll r , ll x)
{
	if (l > x || r < x) return;
	if (l == r) 
	{
	  st[id]++;
	  return ;
    }
	ll mid = ( l + r ) / 2;
	update( id * 2 , l , mid , x);
	update( id * 2 + 1, mid + 1, r , x);
	st[id] = st[id * 2] + st[id * 2 + 1];
}
ll get(ll id, ll l , ll r, ll f)
{
	if( l == r) return r;
	ll mid = ( l + r ) / 2;
	if (st[id * 2] + res >= f) return get(id * 2 , l , mid, f);  
	else
	{
		res += st[id * 2]; 
		return get(id * 2 + 1, mid + 1 , r , f);
	}
}
int main()
{
	file();
   cin >> n >> m >> q;
   for (ll i = 1; i <= n; i++) cin >> x[i], a[x[i]].fi++;
   for (ll i = 1; i <= m; i++) a[i].se = i;
   sort( a + 1 , a + m + 1);
   for (ll i = 1 ; i <= q ; i++) 
   {
   	   cin >> query[i].fi ;
	   query[i].se = i;
   }
   sort(query + 1, query + q + 1 );
   num = n;
   while(qr <= q && query[qr].fi <= num)   ans[query[qr].se] = x[query[qr].fi] , qr ++;
   for(ll i = 1; i <= m ; i++)
   {
   	  update( 1 , 1 , m , a[i].se);
   	  while(a[i].fi == a[i + 1].fi && i < m) i++ , update( 1 , 1 , m , a[i].se);
   	  if(i == m) break;
   	  ll w =  (a[i + 1].fi - a[i].fi);
   	  while(qr <= q && query[qr].fi <= w * i + num)
   	     {
   	  	      ll du = (query[qr].fi - num) % i;
   	  	      if ( du == 0) du = i;
   	  	      res = 0;
   	  	      ans[query[qr].se] = get(1 , 1 , m, du) ;
   	  	      qr++;
		 }
   	  num += w*i; 
   }
   for (ll i = qr  ; i <= q ; i++)  
   {
   	          ll du = (query[i].fi - num) % m;
   	  	      if ( du == 0) ans[query[i].se] = m ;
   	  	      else  ans[query[i].se] = du ;
   }
  for (ll i = 1; i <= q ; i++) cout << ans[i] << '\n';
  return 0;
}  

