#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 25 , MOD = 1e9 +7;
ll f[1 << N] , n , a[N] , pos , le[N] , ri[N] , Max = 0;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
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
	file();
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    
    for (int mask = 0 ; mask < (1 << n) ; mask++)
    {
    	if (f[mask] == 0 && mask != 0) continue;
    	Max = max (Max , f[mask]);
    	pos = 0;
    	for (int i = 1 ; i < n - 1 ; i++)
    	{
    		le[i] = pos;
    		if (!BIT(mask , i)) pos = i;
		}
		pos = n - 1;
		for (int i = n - 2 ; i >= 1 ; i--)
    	{
    		ri[i] = pos;
    		if (!BIT(mask , i)) pos = i;
		}
		for (int i = 1 ; i < n - 1 ; i++)
    	{
    		if (!BIT(mask , i)) 
    		{
    			int newmask = mask | (1 << i);
    			f[newmask] = max(f[newmask] , f[mask] + a[le[i] + 1] * a[ri[i] + 1]);
			}
		}
	}
	cout << Max;
	return 0;
}

