#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 500005 ,  inf = 1e9 + 7;
void file()
{
	freopen("BoundSeq.inp" , "r" , stdin);
    freopen("BoundSeq.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N];

namespace sub1
{
	int ans = -1;
	void solve()
	{
		for(int i = 1 ; i <= n ; i++)
		{
		  int Min = a[i];
		  for(int j = i - 1 ; j >= 1 ; j--)
		  {
		  	if(a[j] > a[i]) break;
		  	if(a[j] <= Min) ans = max(i - j + 1 , ans);
		  	Min = min(Min , a[j]);
		  }
	   }
	   cout << ans ;
	}
}

namespace sub2
{
	int ans = 0 , r[N] , l[N] ;
	
	void maxmin()
	{
		deque<int> dq;
		
		for(int i = 1 ; i <= n ; i++)
		{
			while(dq.size() && a[i] >= a[dq.back()]) dq.pop_back();
			if(dq.size()) l[i] = dq.back() + 1;
			else l[i] = 1;
			dq.pb(i);
		}
		
	 dq.clear();
	    
	    for(int i = n ; i >= 1 ; i--)
	    {
	    	r[i] = i;
	    	while(dq.size() && a[i] <=  a[dq.back()]) dq.pop_back() ;
	    	if(dq.size()) r[dq.back() - 1] = min(i , r[dq.back() - 1]);
	    	else r[n] = min(i , r[n]) ;
	    	dq.pb(i);
		}
	}
	
	void solve()
	{
		maxmin();
		int Min = inf;
		for(int i = n ; i >= 1 ; i--)
		{
			Min = min(r[i] , Min);
			ans = max(ans , i - max(Min , l[i]) + 1);
		}
		
	 if(ans > 1)	cout << ans;
	 else cout << -1;
	}
}

int main()
{
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  if(n <= 3000) sub1::solve();
  if(n > 3000) sub2::solve();
  return 0;
}

