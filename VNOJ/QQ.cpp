#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , a[N] , b[N] , s[N];
void file()
{
	freopen("QQ.inp" , "r" , stdin);
	freopen("QQ.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll solve(ll x[N] , ll y[N])
{
	ll  ans = 0;
    for (int i = 1 ; i <= n ; i++) s[i] = y[i] - i + 1;
	sort(s + 1 , s + n + 1);
	for (int i = 1 ; i <= n ; i++) ans = ans + abs(x[i] - x[n/2 + 1]) + abs(s[i] - s[n/2 + 1]);
	return ans;
}
int main()
{
	file();
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)	 cin >> a[i] >> b[i];
    sort(a + 1 , a + n + 1);
    sort(b + 1 , b + n + 1);
    cout << min(solve(a , b) , solve(b , a)) ;
}

