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
ll n , t , a[N] , stmax[N][25] , stmin[N][25] , Log[N];
int ans = 0;
bool check(int x , int y)
{
	int j = Log[y - x + 1];
    ll minimum = min(stmin[x][j] , stmin[y - (1 << j) + 1][j]);
    ll maximum = max(stmax[x][j] , stmax[y - (1 << j) + 1][j]);
    if (maximum - minimum <= t) return true;
    return false;
}

int main()
{
	file();
  cin >> n >> t;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  
  for (int i = 1 ; i <= n ; i++) stmax[i][0] = stmin[i][0] = a[i];
  for (int j = 1 ; (1 << j) <= n ; j++)
  for (int i = 1 ; i + (1 << j) - 1 <= n ; i++)
  {
  	stmax[i][j] = max(stmax[i][j - 1] , stmax[i + (1 << (j - 1))][j - 1]);
  	stmin[i][j] = min(stmin[i][j - 1] , stmin[i + (1 << (j - 1))][j - 1]);
  }
 
  Log[1] = 0;
  for (int i = 2; i <= n; i++)
    Log[i] = Log[i/2] + 1;
    
  for (int i = 1 ; i <= n ; i++)
  {
  	int d = 1 , c = i , kq = -1 , g ;
  	while (d <= c)
  	{
  		g = (d + c) / 2;
  		if(check(g , i)) kq = g , c = g - 1;
  		else d = g + 1;
	}
	if (kq != -1) ans = max(ans , i - kq + 1);
  }
  cout << ans;
  return 0;
}

