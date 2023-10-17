#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2000005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("GRN.inp" , "r" , stdin);
	freopen("GRN.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , d[N] , ans = 0;
map<ll , ll> pos;
vector<ll> diff;

bool check(ll x)
{
//	cout << x << ' ';
	int id;
	for(int i = 1 ; i <= n ; i++) d[i] = 0;
  	for(int i = 1 ; i <= n ; i++)
  	  {
  		 if(d[i] == 1) continue;
  		 id = pos[a[i] + x] ;
  		 if(id == 0) return false;
  		 d[id] = 1;
  	  }
  	 // cout << x << ' ';
	  return true;
}

int main()
{
	file();
	
  cin >> n;
  
  if(n > 1000)
  {
  	for(int i = 1 ; i <= n ; i++) if(n % i == 0) ans++;
  	cout << ans ;
  	return 0;
  }
  
  n = n * 2;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  sort(a + 1 , a + n + 1);
  pos[a[1]] = 1;
  for(int i = 2 ; i <= n ; i++) diff.pb(a[i] - a[1]) , pos[a[i]] = i;
  for(auto x : diff)	if(check(x)) ans++;
  cout << ans;
  return 0;
}

