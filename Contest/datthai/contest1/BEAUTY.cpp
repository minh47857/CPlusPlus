#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const ll N = 3e5 + 5;
const ll INF = 1e15;
ll n , a[N] , s[N] , Min[N] , ans = -INF;
void file()
{
   freopen("BEAUTY.inp" , "r" , stdin);
	freopen("BEAUTY.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int main()
{
    file();
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
        cin >> a[i] , s[i] = s[i - 1] + a[i];
    for (ll i = 1 ; i <= n ; i++)
        Min[i] = min(Min[i - 2] , s[i]);
    for (ll i = 4 ; i <= n ; i++)
        ans = max(ans , s[i] - Min[i - 4]);
    cout << ans;
    return 0;
}
