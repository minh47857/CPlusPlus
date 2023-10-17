#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 23, MOD = 1e9 +7;
ll ans = -1 , mark , h[N] , w[N] , s[N];
int n ;
pi f[1 << N];
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int Bit(int x , int k)
{
	return (x >> k) & 1;
}
int main()
{
   cin >> n >> mark;
   for (int i = 1; i <= n ; i++) cin >> h[i] >> w[i] >> s[i] ;
   for (int i = 1 ; i < (1 << n) ; i ++) f[i] = {-1 , -1};
   for (int mask = 0; mask < ( 1 << n) ; mask++ )
   {
   	
   	
   	
   	 if (f[mask].fi == -1 ) continue;
   	 if (f[mask].fi >= mark) ans = max(ans , f[mask].se);
   	  for (int i = 0; i < n ; i ++)
   	  {
   	  	if (!Bit(mask , i) )
   	  	 {
   	  		int newmask = mask | (1 << i);
   	  		
   	  		if (mask == 0) f[newmask] = {h[i + 1] , s[i + 1]};
   	  		
   	  		else
   	  		{
   	  			ll	len = f[mask].fi;
   	  	        ll	hea = f[mask].se - w[i + 1];
   	  		if (hea < 0) continue;
   	  		if (min (hea , s[i + 1]) > f[newmask].se) f[newmask] = { len + h[i + 1] , min (hea , s[i + 1]) } ;
		    }
   	  	
	     }
	  }
   }
   if (ans == - 1) cout << "Mark is too tall";
   else cout << ans;
   return 0;
}

