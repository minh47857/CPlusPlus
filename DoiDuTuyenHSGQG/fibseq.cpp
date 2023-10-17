#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100006 , MOD = 1e9 +7 , inf = 1e15;
ll f[60] , a[N] , ans = 0 , s[N] , n , p , q;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll tknp(ll l , ll r , ll x)
{
	ll d = l , c = r , g , kq = -1;
	while(d <= c)
	{
		g = (d + c) / 2;
		if (s[g] == x) return g ;
		if (s[g] < x) d = g + 1 ;
		else c = g - 1;
	}
	return -1;
}
bool check(ll x)
{
	ll d = 1 , c = 56 , kq = 0 ,  g ;
	while (d <= c)
	{
		g = (d + c) / 2;
		if (f[g] == x) return true;
		if (f[g] > x) c = g - 1;
		if (f[g] < x) d = g + 1;
	}
	return false;
}
int main()
{
	file();
	cin >> n >> p >> q ;
	s[0] = 0;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i] ;
	f[1] = 0 , f[2] = 1;
    for (int i = 3 ; i <= 56; i++) f[i] = f[i - 1] + f[i - 2]  ;
    
    if (n > 1e4)
    {
    	
    for (int i = 1 ; i <= n ; i++)
    {
    	for (int j = 1 ; j <= 56 ; j++)
    	{
    		if (j == 3) continue;
    		if (s[i] < f[j]) break;
    		ll pos = tknp(0 , i , s[i] - f[j]);
    		if (pos == -1) continue;
    	ll	pos1 = pos - 1 , pos2 = pos + 1;
    		while (pos1 >= 0 && s[pos1] == s[i] - f[j] && i - pos1 >= p && i - pos1 <= q) ans++ , pos1--;
    		while (pos2 <= i && s[pos2] == s[i] - f[j] && i - pos2 >= p && i - pos2 <= q) ans++ , pos2++;
    		
    	    if (i - pos  >= p && i - pos  <= q) ans ++;
		}
    }
	cout << ans ;
	return 0;
   }
	ll res = 0;
	for(int l = 1 ; p + l - 1 <= n ; l++)
        {
            ll sum = 0;
            for(int i = l ; i < p + l - 1 ; i++) 	sum += a[i];
            for(int i = p + l - 1 ; i <= min(q + l - 1 , n) ; ++i)
            {
                sum += a[i];
                if(check(sum)) res++;
            }
        }
  cout << res;
}

