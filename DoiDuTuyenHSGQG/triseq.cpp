#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 22 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub2
{
	ll f[N][N][N][N] , a[N] , n , t;
	ll calc(int id , int min1 ,int min2 , int maxx)
	{
	//	cerr << id << ' ' << min1 << ' ' << min2 << ' ' << maxx << '\n';
	//	if(i == 2) exit(0);
		if(f[id][min1][min2][maxx] != -1) return f[id][min1][min2][maxx];
		if(id >= n)
		{
			f[id][min1][min2][maxx] = 1;
			return 1;
		}
		ll cnt = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			int n_min1 , n_min2 , n_maxx;
			n_min1 = min1;
			n_min2 = min2;
			n_maxx = maxx;
			if(i < n_min1)
			{
				n_min2 = n_min1;
				n_min1 = i;
			}
		    else if(i < n_min2) n_min2 = i;
			if(i > n_maxx) n_maxx = i;
			if(n_min1 + n_min2 > n_maxx || id <= 1) cnt += calc(id + 1 , n_min1 , n_min2 , n_maxx);
		}
		f[id][min1][min2][maxx] = cnt;
		return cnt;
	}
	
   	ll get(int id , int min1 ,int min2 , int maxx)
	{
		//cerr << id << ' ' << min1 << ' ' << min2 << ' ' << maxx << '\n';
	//	if(i == 2) exit(0);
		if(id >= n) return 1;
		ll cnt = 0;
		for(int i = 1 ; i <= a[id + 1] ; i++)
		{
			int n_min1 , n_min2 , n_maxx;
			n_min1 = min1;
			n_min2 = min2;
			n_maxx = maxx;
			if(i < n_min1)
			{
				n_min2 = n_min1;
				n_min1 = i;
			}
		    else if(i < n_min2) n_min2 = i;
			if(i > n_maxx) n_maxx = i;
			if(i == a[id + 1]) cnt += get(id + 1 , n_min1 , n_min2 , n_maxx);
		    else	if(n_min1 + n_min2 > n_maxx || id <= 1) cnt += f[id + 1][n_min1][n_min2][n_maxx];
		}
		return cnt;
	}
	
	void find(int id , int min1 ,int min2 , int maxx , ll val)
	{
		//cerr << id << ' ' << min1 << ' ' << min2 << ' ' << maxx << '\n';
	//	if(i == 2) exit(0);
		if(id >= n) return ;
		ll cnt = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			int n_min1 , n_min2 , n_maxx;
			n_min1 = min1;
			n_min2 = min2;
			n_maxx = maxx;
			if(i < n_min1)
			{
				n_min2 = n_min1;
				n_min1 = i;
			}
		    else if(i < n_min2) n_min2 = i;
			if(i > n_maxx) n_maxx = i;
		   	if(n_min1 + n_min2 > n_maxx || id <= 1) cnt += f[id + 1][n_min1][n_min2][n_maxx];
		   	if(cnt >= val)
		   	{
		   		cout << i << ' ';
		   	   find(id + 1 , n_min1 , n_min2 , n_maxx , val - cnt + f[id + 1][n_min1][n_min2][n_maxx]);
		   	   break;
			}
		}
	}
	
	
	
	
	void solve()
	{
		cin >> n >> t;
		memset(f , -1 ,sizeof(f));
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		cout << calc(0 , n + 1 , n + 1 , 0) << '\n' ;
		find(0 , n + 1 , n + 1 , 0 , t) ;
		cout << '\n' << get(0 , n + 1 , n + 1 , 0) << '\n';	
			
	}
}

int main()
{
	file();
   sub2::solve();
}

