#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("TwoPress.inp" , "r" , stdin);
	freopen("TwoPress.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , s , x , a[N] , c[105];

namespace sub12
{
	ll ans = 0;
	void solve()
	{
	   for(int i = 1 ; i <= n ; i++)
	     for(int j = i + 1 ; j <= n ; j++)
	       for(int k = j + 1 ; k <= n; k++)
	       {
	       	if(c[a[i]] + c[a[j]] + c[a[k]] <= s) ans++;
		   }
	    cout << ans;
    }
}

namespace sub3
{
	ll ans = 0 , bit[1000005];
	
	ll get(ll p)
	{
	//	cout << "get" << p << '\n';
		ll res = 0;
		for(ll i = p ; i >= 1 ; i -= (i & (-i))) res += bit[i];
		return res;
	}
	
	void update(ll u)
	{
	//	cout << "update" << u << '\n';
		for(ll i = u ; i <= s ; i += (i & (-i))) bit[i]++;
	}
	
	void solve()
	{
		update(c[a[1]]);
		for(int i = 2 ; i < n ; i++)
		{
			//cout << c[a[i]] <<'\n';
			for(int j = i + 1 ; j <= n ; j++)	ans += get(s - c[a[j]] - c[a[i]]);
		    update(c[a[i]]);
		}
		cout << ans;
	}
}

ll calc(ll k)
{
	if(k == 1) return x;
	ll p = x , res = 0;
		while(p)
		{
			if(p % k == 0) p = p / k;
			else p--;
			res++;
			if(res >= s) return inf;
		}
		return res;
}
	
int main()
{
	file();
  cin >> n >> s >> x;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  for(int i = 1 ; i <= 100 ; i++) c[i] = calc(i) ;//, cout << i << ' ' << c[i] << '\n';
 // cout << c[2] << ' ' <<  << endl;
 //for(int i = 1 ; i <= n ; i++) cout << c[a[i]] << ' ';
  if(n <= 100) sub12::solve() ;
  else   sub3::solve();
}

