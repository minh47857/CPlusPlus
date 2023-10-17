#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7;
ll n , m , s[N][N] , a[N][N] , Max = 0 , st[N] , endd[N];
deque <ll> dq;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(int v)
{
    
	dq.clear();
	for (int i = 1; i <= m ; i++)
	{
		while (dq.size() && a[v][dq.back()] >= a[v][i]) dq.pop_back();
		if(dq.size() == 0) st[i] = 0;
		else  st[i] = dq.back();
		dq.push_back(i);
	}
	dq.clear();
	for (int i = m; i >= 1 ; i--)
	{
		while (dq.size() && a[v][dq.back()] >= a[v][i]) dq.pop_back();
		if(dq.size() == 0) endd[i] = m + 1;
		else  endd[i] = dq.back();
		dq.push_back(i);
	}
	
	for (int i = 1 ; i <= m ; i++)		Max = max(Max , (endd[i] - st[i] - 1) * a[v][i]) ;
}
int main()
{
	file();
   cin >> n >> m;
   for (int i = 1; i <= n ;i++)
   for (int j = 1; j <= m ; j++)
   cin >> s[i][j];
   for (int i = 1 ; i <= n ;i++)
   for (int j = 1; j <= m ; j++)
    	if (s[i][j] == 1) a[i][j] = a[i - 1][j] + 1;
   for (int i = 1; i <= n ; i++) solve(i);
   cout << Max;
   return 0;
}

