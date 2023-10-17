#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2e5 + 5 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("Connect.inp" , "r" , stdin);
	freopen("Connect.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , d ;

namespace sub1
{
	struct node
	{
		ll val , u , v;
	};
	
	bool operator < (const node&a , const node&b)
	{
		return a.val < b.val;
	}
	
	vector<node> Q;
	ll par[1005] , a[1005] , ans = 0;
	
	int parent(int x)
	{
		if(par[x] < 0) return x;
		par[x] = parent(par[x]);
		return par[x];
	}
	
	bool merge(int x , int y)
	{
		if((x = parent(x)) == (y = parent(y))) return false;
		if(par[x] > par[y]) swap(x , y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	
	void solve()
	{
		memset(par , -1 , sizeof(par));
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		for(int i = 1 ; i <= n ; i++)
		 for(int j = i + 1 ; j <= n ; j++)
		   Q.pb({a[i] + a[j] + (j - i) * d , i , j});
		sort(Q.begin() , Q.end());
		for(auto x : Q)
	     {
	     	if(merge(x.u , x.v)) ans += x.val;
		 }
		  cout << ans; 
	}
}

namespace sub2
{
	ll a[N] , ans = 0;
	void solve()
	{
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		sort(a + 1 , a + n + 1);
		for(int i = 2 ; i <= n ; i++) ans += (a[1] + a[i]);
		cout << ans;
	}
}

int main()
{
	file();
  cin >> n >> d;
  if(n <= 1000) sub1::solve();
  else if(d == 0) sub2::solve();
}

