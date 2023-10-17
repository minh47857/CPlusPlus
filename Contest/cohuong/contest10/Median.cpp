#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("Median.inp" , "r" , stdin);
	freopen("Median.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N];

namespace sub1
{
	ll f = 1 , s[25];
	vector<ll> num;
	void gen(int t)
	{
		for(int i = 0 ; i <= 1 ; i++)
		{
			if(i == 1) s[i] = s[i - 1] + a[t];
			if(t == n) num.pb(s[i]);
			else gen(t + 1);
			if(i == 1) s[i] -= a[t];
		}
	}
	
	void solve()
	{
		gen(1);
		sort(num.begin() , num.end());
		for(int i = 1 ; i <= n ; i++) f = f * 2; 
		cout << num[f / 2];
	}
}

int main()
{
//	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  if(n <= 20) sub1::solve();
 // else sub2::solve();
}

