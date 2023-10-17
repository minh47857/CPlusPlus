#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
void file()
{
	freopen("FRACTION.inp" , "r" , stdin);
	freopen("FRACTION.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
struct node
{
	ll fi , se , id ;
};
bool operator < (const node&x , const node&y)
{
	return x.fi * y.se < y.fi * x.se;
}
ll  n , w , pos[N] , st[N] ;
node a[N];
void update(int id , int l , int r , int x , int num)
{
	if ( l > x || r < x ) return;
	if (l == r)
	{
		st[id] = num ;
		return ;
	}
	int mid = (l + r) / 2 ;
	update(id * 2 , l , mid , x , num);
	update(id * 2 + 1 , mid + 1 , r , x , num);
	st[id] = max (st[id * 2] , st[id * 2 + 1]);
}
ll get(int id , int l , int r , int x)
{
	if (l > x ) return 0 ;
	if (r <= x) return st[id];
	int mid = (l + r) / 2;
	return max ( get(id * 2 , l , mid , x) , get(id * 2 + 1 , mid + 1 , r , x) );
}
void w1 ()
{
   for (int i = 1 ; i < 2 * n ; i += 2) 
   {
   	cin >> a[i].fi >> a[i].se ;
   	ll x = __gcd (a[i].fi , a[i].se);
   	a[i].fi = a[i].fi / x;
   	a[i].se = a[i].se / x;
   	a[i].id = i ;
   	a[i + 1] = {a[i].se , a[i].fi , i + 1};
   }
   sort ( a + 1 , a + 2 * n + 1 ) ;
   for (int i = 1 ; i <= 2 * n ; i++)
   {
   	   if (a[i].fi == a[i - 1].fi && a[i].se == a[i - 1].se) pos[a[i].id] = pos[a[i - 1].id];
	   else  pos[a[i].id] = i ;
   }
   for (int i = 1 ; i < 2 * n ; i += 2)
   {
     ll ans1 = get (1 , 1 , 2 * n , pos[i] - 1) ,
        ans2 = get (1 , 1 , 2 * n , pos[i + 1] - 1);
     update(1 , 1 , 2 * n , pos[i] , ans1 + 1);
     update(1 , 1 , 2 * n , pos[i + 1] , ans2 + 1);
   }
}
void w0 ()
{
   for (int i = 1 ; i <= n ; i ++) 
   {
   	cin >> a[i].fi >> a[i].se ;
   	ll x = __gcd (a[i].fi , a[i].se);
   	a[i].fi = a[i].fi / x;
   	a[i].se = a[i].se / x;
   	a[i].id = i ;
   }
   sort ( a + 1 , a + n + 1 ) ;
   for (int i = 1 ; i <= n ; i++)
   {
   	   if (a[i].fi == a[i - 1].fi && a[i].se == a[i - 1].se) pos[a[i].id] = pos[a[i - 1].id];
	   else  pos[a[i].id] = i ;
   }
   for (int i = 1 ; i <= n ; i ++)
   {
     ll ans = get (1 , 1 ,  n , pos[i] - 1) ;
     update(1 , 1 , n , pos[i] , ans + 1);
   }
}
int main()
{
	file();
    cin >> n >> w;
    if (w == 0) w0()  ; else w1(); 
    cout << st[1] ;
}
