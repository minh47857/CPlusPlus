#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7 , inf = 1e15;
ll a[N] , t , le[N] , pos[N] , ri[N];
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve()
{
    ll res = 0 , n;
    deque <ll> dq;
    cin >> n ;
    memset()
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    
   for (int i = 1 ; i <= n ; i++)
   {
   	 while (dq.size() && a[i] <= a[dq.back()]) dq.pop_back();
   	 if (!dq.size()) pos[i] = 0;
   	 else pos[i] = dq.back();
   	 dq.push_back(i);
   }
   for (int i = 1 ; i <= n ; i++) le[i] = le[pos[i]] + a[i] * (i - pos[i]);
   dq.clear();
    for (int i = n ; i >= 1 ; i--)
   {
   	 while (dq.size() && a[i] <= a[dq.back()]) dq.pop_back();
   	 if (!dq.size()) pos[i] = n + 1;
   	 else pos[i] = dq.back();
   	 dq.push_back(i);
   }
   for (int i = n ; i >= 1 ; i--) ri[i] = ri[pos[i]] + a[i] * (pos[i] - i);
   
   for (int i = 1 ; i <= n ; i++) res = max(res , le[i] + ri[i] - a[i]) ;
    cout << res << '\n';
}
int main()
{
    cin >> t;
  while (t--) solve();

}

