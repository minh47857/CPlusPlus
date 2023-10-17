#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , s = 0 , ans = 0 , Min ;
pi a[N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
   cin >> n ;
   for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se ;
   sort(a + 1 , a + n + 1);
   Min = -a[1].fi;
   for (int i = 1 ; i <= n ; i++)
   {
   	s = s + a[i].se;
   	ans = max(s - Min - a[i].fi , ans);
    Min = min (Min , s - a[i + 1].fi);
   }
   cout << ans;
   return 0;
}

