#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 1e9 +7 , inf = 1e14;
ll n , m , k , l , r , res , Bit[N] , s[N] , x ;
map<ll , ll> pos ;
vector <ll> v;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(int u)
{
	ll res = 0;
    for (int i = u ; i >= 1 ; i -= (i & (-i))) res += Bit[i];
    return res;
}
void update(int x)
{
	for (int i = x ; i <= m ; i  += (i & (-i))) Bit[i]++;
}
ll check(ll x)
{
	memset(Bit , 0 , sizeof(Bit));
	ll ans = 0;
	update(pos[0]);
	for (int i = 1 ; i <= n ; i++)
	{
		ll tmp = s[i] - x;
		ll d = 0 , c = n , g , kq = -1;
		while (d <= c)
		{
			g = (d + c) / 2;
			if (v[g] <= tmp) kq = g , d = g + 1;
			else c = g - 1;
		}
		if (kq == -1) 
		{
			update(pos[s[i]]);
			continue;
		}
		ans += get(pos[v[kq]]);
		update(pos[s[i]]);
	}
	return ans;
} 
int main()
{
	file();
   cin >> n >> k;
   s[0] = 0;
   v.pb(0);
   for (int i = 1 ; i <= n ; i++) cin >> x , s[i] = s[i - 1] + x , v.pb(s[i]);
   sort(v.begin() , v.end());
   for (int i = 0 ; i < v.size() ; i++) 
   if (v[i] == v[i - 1] && i >= 1) pos[v[i]] = pos[v[i - 1]];
   else pos[v[i]] = i + 1;
   m = v.size();
   l = -inf , r = inf ;
   while(l <= r)
   {
   	 ll mid = (l + r) / 2;
   	 ll w = check(mid);
   	 if (w >= k) 
		{
			res = mid ; 
			l = mid + 1;
		}
   	else r = mid - 1;
   }
   cout << res;
}

