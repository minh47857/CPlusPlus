#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll t , n , dp[N] , a[N] , st[N] , ed[N] , sum[N];
deque <ll> dq;
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve()
{
    memset(dp , 0 , sizeof(dp));
    memset(sum , 0 , sizeof(sum));
    cin >> n;
    dp[0] = 1;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    dq.clear();
    for (int i = 1 ; i <= n ; i++)
    {
        while(dq.size() && a[i] < a[dq.back()]) dq.pop_back();
        if (dq.size() == 0) st[i] = 1 ;
        else st[i] = dq.back() + 1 ;
        dq.push_back(i);
    }
    dq.clear();
    for (int i = n ; i >= 1 ; i--)
    {
        while(dq.size() && a[i] <= a[dq.back()]) dq.pop_back();
        if (dq.size() == 0) ed[i] = n ;
        else ed[i] = dq.back() - 1 ;
        dq.push_back(i);
    }
    for (int i = 1 ; i <= n ; i++)
    {
    ll    res1 = 1 ;
    ll    res2 = ed[i] - st[i] + 1;
  // cout << res1 << ' ' << res2 << ' '  << st[i]<< ' ' << ed[i] << endl;
    if (res2 - res1 > 1 && i != st[i] && i!= ed[i])
    {
        sum[res1] += a[i] , sum[res1 + 1] -= a[i];    
        sum[res2] += a[i] , sum[res2 + 1] -= a[i];
        dp[res1 + 1]--;
        dp[res2] ++;
    }
    if (res1 == res2)
    {
        sum[res1] += a[i];    
        sum[res1 + 1] -= a[i];
        if (a[i] > n - res1 + 1) dp[res1]-- , dp[res1 + 1]++;
        continue;
    }
        if(i == st[i] || i == ed[i]) sum[res1] += a[i] , sum[res2 + 1] -= a[i];
        if (a[i] > n - res1 + 1 ) dp[res1]-- , dp[res1 + 1]++;
        if (a[i] > n - res2 + 1) dp[res2]-- , dp[res2 + 1]++; 
    }
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i] = dp[i] + dp[i - 1] , sum[i] = sum[i] + sum[i - 1];
    //    cout << dp[i] << ' ' << sum[i] <<endl;
        if (dp[i] == 1)
        { 
        ll len = n - i + 1;
            if (2 * sum[i] == len * (len + 1)) cout << 1;
            else cout << 0;
        }
        else cout << 0;
    }
    cout << '\n';
}
int main()
{
   cin >> t;
   while(t--)  solve();
   return 0;
}

