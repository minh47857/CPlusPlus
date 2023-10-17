#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get_deque (int n , int k)
{
	deque <ll> dqmax , dqmin;
	ll res = 0 ;
	for (int i = 1; i <= n ; i++)
	{
		while (dqmax.size() && vmax[i] >= vmax[dqmax.back()]) dqmax.pop_back();
		while (dqmin.size() && vmin[i] <= vmin[dqmin.back()]) dqmin.pop_back();
		dqmax.push_back(i);
		dqmin.push_back(i);
	}
}
ll get(int m , int n , int k , int a[302][302])
{
	ll res = 0 ;
	for (int i = 1; i <= m ; i++) pre[i] = 0;
	for (int i = 1 ; i <= m ; i++)
	{
		for (int i = 1 ; i <= n ; i++) vmin = 1e9 , vmax = -1e9;
		for (int j = i ; j <= m ; j++)
		{
			for (int l = 1 ; l <= n ; l++)	vmin[l] = min(vmin[l] , a[j][l])   , vmax[l] = max(vmax[l] , a[j][l]);
			are = get_deque(n , k) * (j - i + 1);
			res = max (are + pre[i - 1] , res);
			pre[j] = max ({pre[j] , pre[j - 1] , are});
		}
	}
	
}
int main()
{
	cin >> m >> n;
    for (int i = 1; i <= m ; i ++) 
    for (int j = 1; j <= n ; j ++)
    cin >> a[i][j];
   res =  get (m , n , k , A);
}

