#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , k , a[N] ,t;
deque <ll> dq;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve()
{
	cin >> n >> k; 
	for (int i = 1; i <= n ; i++) cin >> a[i];
	dq.clear();
	for (int i = 1; i <= n ; i++)
	{
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push_back(i);
		if (dq.front() + k <= i) dq.pop_front();
		if (i >= k) cout << a[dq.front()] << ' ';
	}
	cout << '\n';
}
int main()
{
	file();
  cin >> t ;
  while (t --) solve();
  return 0;
}

