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
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct bridge
{
	ll order , sum ;
};

ll t , n , End[N] , res1 , res2  , Time;
pi a[N];
bridge id[N];

void solve()
{
	deque<int> dq;
	memset(End , 0 , sizeof(End));
	Time = res1 = res2 = 0;
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
  sort(a + 1 , a + n + 1);
  for(int i = 1 ; i <= n ; i++)
  {
  	while(dq.size() && a[i].se > a[dq.back()].se) dq.pop_back();
  	
  	if(!dq.size() || (dq.size() && a[dq.back()].se != a[i].se)) id[i] = {++Time , a[i].fi};
  	else 
	  {
	    id[i] = {id[dq.back()].order , (id[dq.back()].sum + a[i].fi) % MOD };
	    res1 = (res1 + ( 2 * a[i].fi * id[dq.back()].sum) % MOD) % MOD;
	  }
	  
	  dq.pb(i);
  }
//  cout << res1 << ' ';
  for(int i = 1; i <= n; i++) End[id[i].order]++;
  
  for(int i = 1 ; i <= n ; i++)
  {
 // 	cout << id[i].order << ' ' << id[i].sum << ' ' << id[i].num << ' ' << End[id[i].order] << '\n';
  	res2 = (res2 + (((a[i].fi * a[i].fi) % MOD ) * (End[id[i].order] - 1)) % MOD) % MOD;
  }
   cout << (res2 - res1 + MOD) % MOD << '\n';
}

int main()
{
	cin >> t;
	while(t--) solve();
}

