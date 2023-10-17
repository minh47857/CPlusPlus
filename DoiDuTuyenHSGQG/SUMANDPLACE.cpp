#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e6 + 5 , MOD = 1e9 +7;
ll a , b  , d[N] , t , n , m  , s[N];
pi st[4 * N];
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void snt() 
{
    for (ll i = 1 ; i <= 1e6 ; i++)
    for (ll j = i  ; j <= 1e6 ; j += i) d[j] ++;
}
void build (int id ,int l ,int r)
{
	if (l == r) 
	{
		st[id] = make_pair (s[l] , s[l]);
		return ;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid );
	build(id * 2 + 1 , mid + 1 , r );
	st[id].fi = st[id * 2].fi + st[id * 2 + 1].fi;
	st[id].se = max(st[id * 2].se , st[id * 2 + 1].se);
}
void update (int id , int l , int r , int u , int v)
{
	
	if (l > v || r < u) return ;
	if (st[id].se <= 2) return ;
	if (l == r) 
	{
		st[id] = make_pair(d[st[id].fi] , d[st[id].fi]);
		return ;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v);
	update(id * 2 + 1 , mid + 1 ,  r , u , v);
	st[id].fi = st[id * 2].fi + st[id * 2 + 1].fi;
	st[id].se = max(st[id * 2].se , st[id * 2 + 1].se);
}

ll get (int id , int l , int r , int u , int v)
{
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return st[id].fi;
	int mid = (l + r) / 2;
	return get(id * 2 , l , mid , u , v) + get(id * 2 + 1 , mid + 1 , r , u , v);
}
int  main()
{
    file();
    snt();
    cin >> n >> m;
    for (ll i = 1 ; i <= n ; i++) cin >> s[i];
    build(1 , 1 , n);
  while (m --)
  {
  	cin >> t >> a >> b;
  	if (t == 1) update ( 1 , 1 , n , a , b );
  	else 	cout << get(1 , 1 , n , a , b) << '\n';
	
  }
  return 0;
}
