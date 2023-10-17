#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll a , b;
ll calc(ll x)
{
	ll p = 2 , ans = 0 ;
	while(p <= x)
	{
		ans += (x / p);
		p *= 2;
	}
	return ans;
}
int main()
{
	file();
  cin >> a >> b;
  cout <<  calc(b) - calc(a - 1);
  return 0;
}

