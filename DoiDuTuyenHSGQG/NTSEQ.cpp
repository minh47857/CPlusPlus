#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001, MOD = 1e9 + 7;
ll n, pos[N], x;
pi Max, s[N];
vector <pi> a;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi combine(pi x, pi y)
{
	if(x.fi > y.fi) return {x.fi, x.se };
	if(x.fi == y.fi) return {x.fi, (x.se + y.se) % MOD};
	return {y.fi, y.se };
}
pi get(ll id, ll l, ll r, ll x )
{
	if(l > x) return {0 , 0};
	if(r <= x) return s[id];
	ll g = (l + r) / 2; 
	return combine(get(id*2, l, g, x) , get(id*2 + 1, g + 1, r, x));
}
void update(ll id, ll l,ll r, ll x, pi num)
{
	if(l > x || r < x) return ;
	if (l == r) 
	{
		s[id] = combine(s[id], num) ;
		return;
	}
	ll g = (l + r ) / 2;
	update(id*2, l, g, x, num);
	update(id*2 + 1, g + 1, r, x, num);
	s[id] = combine(s[id*2] , s[id*2 + 1]);
}
int main()
{
	file();
   cin >> n;
   for(ll i = 1; i <= n; i++) 
   {
   cin>> x;
    a.pb({ ++ x , i});
   }
   sort(a.begin(), a.end() );
   for ( ll i = 0; i < n; i++ ) 
   {
   	
        if(a[i].fi != a[i-1].fi ) pos[a[i].se] = i + 1 ;  
		else pos[a[i].se] = pos[a[i - 1].se];
		//cout<< a[i].fi << ' ' << a[i].se << ' ' << pos [a[i].se] << endl;;
   }
   for(ll i = 1; i <= n; i++)
   {
      pi val = get(1, 1, n, pos[i]- 1);  
      if(val.fi == 0 && val.se == 0) val = {1, 1};
      else val.fi++ ;
      // cout << val. fi << " "<< val. se << endl ; 
      update(1, 1, n, pos[i], val);
      Max = combine(val , Max);
   } 
   cout << Max.se;
   return 0;
}

