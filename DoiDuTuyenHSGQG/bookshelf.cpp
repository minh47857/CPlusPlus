#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 23 , MOD = 1e9 +7 ,inf = 1e9;
int n , k , num[N] , a[100005] , w[100005][N];
pi f[1 << N] ;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int BIT(int x , int k)
{
	return (x >> k) & 1;
}
int main()
{
   cin >> n >> k; 
   for (int i  = 1; i <= n ; i++) cin >> a[i] ,num[a[i]]++;
   
   for (int i = 1 ;  i <= k ; i++)
   	for (int j = 1; j <= n ; j++)
   	{
   		w[j][i] = w[j - 1][i];
   	  if (a[j] != i) w[j][i] ++;
	}
   
   
   for (int i = 1; i < (1 << k) ; i++) f[i].fi = inf;
   for (int mask = 0 ; mask < (1 << k) ; mask++)
   {
   	 int nn = __builtin_popcount(mask);
   	 for (int i = 0 ; i < k ; i ++ )
   	 {
   	 	if (!BIT(mask , i))
   	 	    {
   	 		 int newmask = mask | ( 1 << i);
   	 		 int c = f[mask].fi + w[f[mask].se + num[i + 1]][i + 1] - w[f[mask].se][i + 1];
   	 		 if ( c < f[newmask].fi) f[newmask] = {c, f[mask].se + num[i + 1]};
			}
	 }
   } 
   cout << f[ (1 << k) - 1 ].fi;
   return 0;
}

