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
	freopen("GAMES.inp" , "r" , stdin);
	freopen("GAMES.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node
{
	int val , lazy;
};

int n , m , a[N] , l , len , r , ans;
node st[4 * N] ;

void dow(int id)
{
	int t = st[id].lazy;
	if(t == 0) return ;
	st[id * 2].val = max(t , st[id * 2].val);
	st[id * 2].lazy = max(t , st[id* 2].lazy);
	st[id * 2 + 1].val = max(t , st[id* 2 + 1].val);
	st[id * 2 + 1].lazy = max(t , st[id* 2 + 1].lazy);
}

void build(int id , int l , int r)
{
	if(l == r)
	{
		st[id].val = st[id].lazy = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 ,  mid + 1 , r);
	st[id].val = max(st[id * 2].val , st[id * 2 + 1].val);
}

void update(int id , int l , int r , int u , int v , ll value)
{
	if(l > v || r < u) return;
	if(l >= u && r <= v) 
	{
		st[id].val = value;
		st[id].lazy = value;
		return;
	}
	dow(id);
	int mid = (l + r) / 2;
	update(id * 2 , l , mid  , u , v , value);
	update(id * 2 + 1 , mid + 1 , r , u , v , value);
	st[id].val = max(st[id * 2].val , st[id * 2 + 1].val);
}

ll get(int id , int l , int r , int u , int v)
{
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return st[id].val;
	dow(id);
	int mid = (l + r) / 2;
	return max(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}

int main()
{
	file();
  cin >> n >> m;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  build(1 , 1 , n);
  for(int i = 1 ; i <= m ; i++)
  {
  	cin >> l >> len;
  	r = min(n , l + len - 1);
  	ans = get(1 , 1 , n , l , r);
  	update(1 , 1 , n , l , r , ans + 1);
  	cout << ans + 1 << '\n';
  }
  return 0;
}

