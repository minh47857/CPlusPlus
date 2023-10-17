#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 105 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string f[N][N][10] , a[N];
int n , k , t;

bool cmp(string x , string y)
{
	return (x + y) > (y + x);
}

int calc(string x)
{
	int res = 0;
	for(int i = 0 ; i < x.size() ; i++) res += (x[i] - '0');
	return res;
}

string Max(string x , string y)
{
	if(x == "*" || x.size() < y.size())  return y;
	if(x.size() == y.size())
	{
		if(x < y) return y;
	}
	return x;
}

void solve()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 0 ; i <= n ; i++)
	  for(int j = 0 ; j <= k ; j++)
	    for(int du = 0 ; du <= 8 ; du++)
	      f[i][j][du] = "*";
	f[0][0][0] = "";
//	for(int i = 1 ; i <= n ; i++) cout << a[i] << ' ';
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j <= k ; j++)
		{
			for(int du = 0 ; du <= 8 ; du++)
			{
				//	cout << i << ' ' << j << ' ' << du << ' ' << f[i][j][du] << endl;
				if(f[i][j][du] == "*") continue;
			
			  f[i + 1][j][du] = Max(f[i + 1][j][du] , f[i][j][du]);
			  if(j < k) f[i + 1][j + 1][(du + calc(a[i + 1])) % 9] = Max(f[i + 1][j + 1][(du + calc(a[i + 1])) % 9] , f[i][j][du] + a[i + 1]);
		    }
		}
	}
	if(f[n][k][0] == "*") cout << -1 << '\n';
	else cout << f[n][k][0] << '\n';
}

int main()
{
	file();
  cin >> t;
  while(t--) solve();
}

