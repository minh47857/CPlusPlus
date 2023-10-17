#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7;

int n , m , a[N] , b[N] , ans = 0 , clis[N];

int main()
{
   cin >> n ;
   for (int i = 1; i <= n ; i ++) cin >> a[i];
   cin >> m;
   for (int i = 1; i <= m ; i++) cin >> b[i];
   for (int i = 1; i <= n ; i++)
   {
   	int Max = 0;
   	for (int j = 1; j <= m ; j++)
    {
   		if (a[i] > b[j]) Max = max(Max , clis[j]);
   		if (a[i] == b[j]) clis[j] = max(Max + 1, clis[j]);
	} 
   }
   for (int i = 1; i <= m ; i++) ans = max( ans , clis[i]);
   cout << ans ;
}

