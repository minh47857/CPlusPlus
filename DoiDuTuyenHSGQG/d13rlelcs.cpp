#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 ;
ll f[N][N] , d[N][N];
string str1 , str2;
vector <pair <char , int>> a , b;
ll solve2()
{
	ll ans = 0 ;
	memset(f , 0 , sizeof(f));
	for (int i = 1 ; i < a.size() ; i++)
	for (int j = 1 ; j < b.size() ; j++)
	{
		if (a[i].fi == b[j].fi ) 
		{
			if(a[i].se == b[j].se)
			{
					f[i][j] = f[i - 1][j - 1] + a[i].se;
					d[i][j] = d[i - 1][j - 1] + 1;
	             	ll	pos1 = i - d[i][j];
		            ll	pos2 = j - d[i][j];
		            ll  num = 0;
			if (pos1 >= 1 && pos2 >= 1 && a[pos1].fi == b[pos2].fi)		num += min(a[pos1].se , b[pos2].se);
			if (i + 1 < a.size() && j + 1 < b.size() && a[i + 1].fi == b[j + 1].fi)	num += min(a[i + 1].se , b[j + 1].se);
			ans = max(ans , f[i][j] + num);
			}
			else 	
			{
				ll num = min(a[i].se , b[j].se);
				if (i + 1 < a.size() && j + 1 < b.size() && a[i + 1].fi == b[j + 1].fi) num += min(a[i + 1].se , b[j + 1].se);
				ans = max(ans , num);
				 
			}
		}
	}
	return ans ;
}

ll solve1_sub2()
{
	ll ans = 0;
	memset(f , 0 , sizeof(f));
	for (int i = 1 ; i < a.size() ; i++)
	for (int j = 1 ; j < b.size() ; j++)
	{
		if (a[i].fi != b[j].fi) 
		{
			f[i][j] = max(f[i][j - 1] , f[i - 1][j]);
			continue;
		}
		ll sum1 , sum2 , jj , ii;
		sum1 = a[i].se , sum2 = b[j].se , jj = j - 1 , ii = i - 1;
		for ( ; ii >= 0 ; ii--)
		{
		  while( jj >= 0 && sum1 >= sum2)
		  {
		  	if(b[jj].fi == a[i].fi) sum2 += b[jj].se;
		  	jj--;
		  }
		  if (sum1 == sum2) f[i][j] = max(f[i][j] , sum1);
		  if (jj == -1) break;
		  f[i][j] = max(f[i][j] , f[ii][jj] + sum1);
		 if(a[ii].fi == a[i].fi) sum1 += a[ii].se;
		}
		sum1 = b[j].se , sum2 = a[i].se , ii = i - 1 , jj = j - 1;
		for ( ; jj >= 0 ; jj--)
		{
		  while( ii >= 0 && sum1 > sum2)
		  {
		  	if(a[ii].fi == a[i].fi) sum2 += a[ii].se;
		  	ii--;
		  }
		  if (ii == -1) break;
		
			  f[i][j] = max(f[i][j] , f[ii][jj] + sum1);
		  if (b[jj].fi == a[i].fi) sum1 += b[jj].se;
		}
			ans = max(ans , f[i][j]); 
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  cin >> str1;
  cin >> str2;
  a.pb({'a' , 0});
  b.pb({'a' , 0});
  for (int i = 0 ; i < str1.size() ; i++) 
  {
  	char x = str1[i];
  	int res = 0;
  	while (str1[i + 1] >= '0' && str1[i + 1] <= '9' && i < str1.size()) 
  	{
  		res = res * 10 + (str1[i + 1] - '0');
  		i++;
	}
	a.pb({x , res});
  }
  for (int i = 0 ; i < str2.size() ; i++) 
  {
  	char x = str2[i];
  	int res = 0;
  	while (str2[i + 1] >= '0' && str2[i + 1] <= '9' && i < str2.size()) 
  	{
  		res = res * 10 + (str2[i + 1] - '0');
  		i++;
	}
	b.pb({x , res});
  }
  cout << solve1_sub2() << '\n' << solve2();
  return 0;
}
