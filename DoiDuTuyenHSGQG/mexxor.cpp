#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll nx[N][3] , check[N] , cnt , a[N] , n , q ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int BIT(int x , int k)
{
	return (x >> k) & 1;
}
void Insert(int x)
{
	int cur = 0 , pos;
	for (int i = 19 ; i >= 0 ; i--)
	{
		pos = BIT(x , i);
		if (nx[cur][pos] == -1) nx[cur][pos] = ++cnt;
		cur = nx[cur][pos];
		//cout << pos << ' ' << cnt << ' ' << cur << endl;
	}
//	cout << endl;
}
void dfs(int cur )
{
	if (nx[cur][1] == -1 && nx[cur][0] == -1) 
	{
		check[cur] = 1;
	//	cout << cur << ' ' << check[cur] << endl;
		return ;
	}
	if (nx[cur][1] != -1)  dfs(nx[cur][1]);
	if (nx[cur][0] != -1)  dfs(nx[cur][0]);
	if (check[nx[cur][1]] * check[nx[cur][0]] == 1) check[cur] = 1;
	else check[cur] = 0;	
	//cout << cur << ' ' << check[cur] << endl;
} 
int solve(int cur , int x)
{
	int ans = 0 , n1 , n2 ;
	for (int i = 19 ; i >= 0 ; i--)
	{
		n1 = 0;
		n2 = 1;
		if (BIT(x , i)) swap (n1 , n2);
		//cout << i << ' ' << cur << ' ' << n1 << ' ' << n2 << ' ' << nx[cur][n1] << ' ' << nx[cur][n2] << ' ';
		if (nx[cur][n1] == -1) 
		{
			ans += (abs(n1 - BIT(x , i)) << i);
			break;
		}
		if (!check[nx[cur][n1]])
		{
			ans += (abs(n1 - BIT(x , i)) << i);
			cur = nx[cur][n1];
		//	cout << ans << ' ' << cur << endl;
		}
		else 
		{
			if (nx[cur][n2] == -1) 
			{
				ans += (abs(n2 - BIT(x , i)) << i);
				break;
			}
			if (!check[nx[cur][n2]])
		   {
			ans += ( abs(n2 - BIT(x , i)) << i);
			cur = nx[cur][n2];
		//	cout << ans << ' ' << cur << endl;
		   }
		}
	}
	return ans;
}
int main()
{
	file();
  cin >> n >> q;
  cnt = 0;
  memset(nx , -1 , sizeof (nx));
  memset(check , 0 , sizeof (check));
  for (int i = 1 ; i <= n ; i++) 
  {
  	int u;
  	cin >> u ;
  	Insert(u);
  }
  dfs (0);
  for (int i = 1 ; i <= q ; i++) cin >> a[i] , a[i] = a[i - 1] ^ a[i] , cout << solve(0 , a[i]) << '\n';
}

