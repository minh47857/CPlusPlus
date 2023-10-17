#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("CONE.inp" , "r" , stdin);
	freopen("CONE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , f[N] , g[N] , c[N] , ans = 0 , st[4 * N];
map<ll , ll> pos;
vector<ll> num;

int calc(ll x)
{
	int res = 0;
	while(x)
	{
		res = res + x % 10;
		x /= 10;
	}
	return res;
}

void update(int id , int l , int r , int p , int val)
{
	if(l > p || r < p) return;
	if(l == r) 
	{
		st[id] = max(val , st[id]);
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , p , val);
	update(id * 2 + 1 , mid + 1 , r , p , val);
	st[id] = max(st[id * 2] , st[id * 2 + 1]);
}

int get(int id , int l , int r , int u , int v)
{
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return st[id];
	int mid = (l + r) / 2;
	return max(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}

int main()
{
	file();
	cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , c[i] = calc(a[i]) , num.pb(a[i]) ;
  sort(num.begin() , num.end());
  num.erase(unique(num.begin() , num.end()) , num.end());
  for(int i = 0 ; i <= num.size() - 1 ; i++) pos[num[i]] = i + 1;
  
  for(int i = 1 ; i <= n ; i++)
  {
  	f[i] = get(1 , 1 , n , 1 , pos[a[i]] - 1) + c[i];
  	update(1 , 1 , n , pos[a[i]] , f[i]);
  }
  
  memset(st , 0 , sizeof(st));
  
  for(int i = n ; i >= 1 ; i--)
  {
  	g[i] = get(1 , 1 , n , 1 , pos[a[i]] - 1) + c[i];
  	update(1 , 1 , n , pos[a[i]] , g[i]);
  }
  
  for(int i = 1 ; i <= n ; i++) ans = max(ans , f[i] + g[i] - c[i]);
  cout << ans;
  return 0;
}

