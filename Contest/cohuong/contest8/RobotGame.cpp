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
	freopen("RobotGame.inp" , "r" , stdin);
	freopen("RobotGame.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;

namespace sub1
{
	ll dem = 0 , f[1 << 23] , c[25][25];
	pi a[25];
	
	int Bit(int x , int k)
	{
		return (x >> k) & 1;
	}
	
	void solve()
	{
		for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
      for(int i = 1 ; i <= n / 2 ; i++)
      for(int j = 1 ; j <= 2 ; j++)
       {
      	dem++;
      	for(int t = 1 ; t <= n ; t++) c[t][dem] = abs(a[t].fi - i) + abs(a[t].se - j) ;// cout << t << ' ' << dem << ' ' << c[t][dem] <<' ' << a[t].fi << ' ' << a[t].se << ' ' << i << ' ' << j  << '\n';
	   }
	   
	   for(int i = 0 ; i < (1 << n) ; i++) f[i] = inf;
	   
	   f[0] = 0; 
	   
	   for(int t = 0 ; t < (1 << n) ; t++)
	     {
	     	if(f[t] == inf) continue;
	     	for(int i = 0 ; i < n ; i++)
	     	{
	     		int s = __builtin_popcount(t);
	     		if(Bit(t , i) == 0)
	     		{
	     			int newbit = t | (1 << i);
	     		//	cout<< t << ' ' << i << ' ' << newbit << ' ' << f[t] + c[i + 1][s + 1] << endl;
	     			f[newbit] = min(f[newbit] , f[t] + c[i + 1][s + 1]);
				 }
			 }
		 }
		 cout << f[(1 << n) - 1];
	}
}
int main()
{
	file();
  cin >> n;
  n = n * 2;
  if(n <= 10) sub1::solve();
}

