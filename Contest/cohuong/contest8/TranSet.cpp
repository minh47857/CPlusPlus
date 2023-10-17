#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1005, MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("TranSet.inp" , "r" , stdin);
	freopen("TranSet.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k[N] , w;
vector<int> s[N];

namespace sub1
{
	int ans = 0;
	void solve()
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(auto x : s[i]) ans = max(ans , k[i] + k[x] - 1);
		}
		cout << ans;
	}
}

namespace sub2
{
	int res = 0;
	vector<int> num;
	int calc(vector<int> x , int p)
	{
		int ans = 0;
		if(p == 1)
		{
				for(auto i : x) ans = max(ans , k[i] + int(x.size())- 1);
				return ans;
		}
		
		for(int i = 0 ; i < x.size() ;i++)
		{
			vector<int> u;
			for(int j = 0 ; j < i ; j++) u.pb(x[j]);
			for(int j = i + 1 ; j < x.size() ; j++) u.pb(x[j]);
			for(auto val : s[x[i]]) u.pb(val);
			ans = max(ans , calc(u , p - 1));
		}
		return ans;
	}
	
	void solve()
	{
		
		for(int i = 1 ; i <= n ; i++)
		{
			num.pb(i);
			res = max(calc(num , w) , res);
			num.pop_back();
		}
		cout << res;
	}
}
int main()
{
	file();
   cin >> n;
   
   for(int i = 1 ; i <= n ; i++) 
   {
   	cin >> k[i] ;
   	for(int j = 1 , x ; j <= k[i] ; j++) cin >> x , s[i].pb(x);
   }
   
   cin >> w;
   if(w == 2) sub1::solve();
   else sub2::solve();
   return 0;
}

