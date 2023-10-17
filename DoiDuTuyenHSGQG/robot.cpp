#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD =939999953;
ll ans = 1 , n ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
file();
   cin >> n ;
   if (n <= 2) 
   {
   	cout << 1 ;
   	return 0;
   }
   if (n >= 19999999)
   {
   	cout << 0;
   	return 0;
   }
    for(ll i = 3 ; i < n ; i++) ans = (ans * ( (i*i) % MOD) )%MOD;
    ans = (ans * 2 * n) % MOD;
   cout << ans;
}

