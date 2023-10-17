#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2001 , MOD = 1e9 +7 , inf = 1e15;
ll n , d , a[N]  , ans = 0 , bit[N] , di[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(ll id)
{
    ll res = 0;
    while(id > 0)
    {
        res = max(res , bit[id]);
        id -= id & (-id);
    }
    return res;
}
void update(ll id, ll tmp)
{
    while(id <= 2 * n)
    {
        bit[id] = max(bit[id], tmp);
        id += id & (-id);
    }
}
int main()
{
	file();
  cin >> n >> d ;
  for (ll i = 1 ; i <= 2 * n ; i++) cin >> a[i] , di[a[i]] = i;
  for (int k = 1 ; k < 2 * n ; k++)
  {
  	memset(bit , 0 , sizeof(bit));
  	vector <ll> v;
     for (int i = k + 1; i <= 2 * n ; i++)  
	 {
	 	vector<ll> tmp;
	 	for (int j = a[i] - d ; j <= a[i] + d ; j++)
	 	{
	 		if ( j <= 2 * n && j >= 1 && j != a[i] && di[j] <= k ) tmp.pb(di[j]);
		}
		sort(tmp.begin() , tmp.end() , greater<ll>());
		for(auto x : tmp) v.pb(x);
	 }
  		for (auto x : v)
  		{
  		 ll p = get(x - 1) + 1;
  		 ans = max(ans , p);
  		 update(x , p);
  		}
	}
	cout << ans ;
	return 0;
}
