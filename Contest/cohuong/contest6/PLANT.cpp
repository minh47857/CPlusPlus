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
	freopen("PLANT.inp" , "r" , stdin);
	freopen("PLANT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node
{
	ll val , lazy;
} st[4 * N];

ll n , a[N] , b[N] , ans  , m;

void dow(int id)
{
	ll t = st[id].lazy;
	st[id * 2].val += t;
	st[id * 2 + 1].val += t;
	st[id * 2 + 1].lazy += t;
	st[id * 2].lazy += t;
	st[id].lazy = 0;
}

void update(int id , int l , int r , int u , int v)
{
	if(l > v || r < u) return;
	if(l >= u && r <= v)
	{
		st[id].val++;
		st[id].lazy++;
		return;
	}
	
	dow(id);
	
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v);
	update(id * 2 + 1 , mid + 1 , r , u , v);
	st[id].val = st[id * 2].val + st[id * 2 + 1].val;
}

ll get(int id , int l , int r , int x)
{
	//cout << l << ' ' << r << ' ' << x << ' ' << st[id].val << '\n';
	if(l > x || r < x) return 0;
	if(l == r) 
	{
		ll t = st[id].val;
		st[id] = {0 , 0};
		return t;
	}
	dow(id);
	int mid = (l + r) / 2;
	return (get(id * 2 , l , mid , x) + get(id * 2 + 1 , mid + 1 , r , x));
}

int main()
{
	file();
 cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i] , m = max(m , b[i]);
  for(int i = 1 ; i <= n ; i++)
  {
  	int l = a[i] + 1 , r = b[i] - 1;
  //	cout << l << ' ' << r << ' ' << a[i] << ' ' << b[i] << '\n';
  	update(1 , 1 , m , l , r);
  	ans = get(1 , 1 , m , a[i]) + get(1 , 1 , m , b[i]);
  	cout << ans << '\n';
  }
 return 0;
}

