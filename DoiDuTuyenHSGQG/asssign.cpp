#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 22 , MOD = 1e9 +7;
int n , b , f[1 << N] , a[N][N]  ;
pair <int , int> po[N];
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int BIT(int x ,int k)
{
	return (x >> k) & 1;
}
int cntBit(int n) 
{
    int cnt = 0;
    for (int i = 0; i < 20; i++)
     if (BIT(n, i)) cnt++;
    return cnt;
}
int main()
{
  cin >> n >> b;
  
  
  for (int i = 1; i <= b ; i++)
  {
  	int k , p , a;
  	cin >> k >>p >>a;
  	po[k].fi = p;
  	po[k].se = a;
  }
  
  for (int i = 1; i <= n ; i++)
  for (int j = 1; j <= n ; j++)
  cin >> a[i][j];
  
  for (int mask = 0; mask < (1 << n) ; mask++)
  {
  	int num = cntBit(mask);
  	for (int i = 0 ; i < n ; i++)
  	{
  		if (! BIT(mask , i))
  		{
  		     int	newmask = mask | (1 << i);
  			int ans = f[mask] + a[i + 1][num + 1];
  		
  			if (ans >= po[num + 1].fi) ans += po[num + 1].se;
  				//cout << ans << endl;
  			f[newmask] = max(f[newmask] , ans);
		  }
	  }
  }
  cout << f[(1 << n) - 1];
  return 0;
}

