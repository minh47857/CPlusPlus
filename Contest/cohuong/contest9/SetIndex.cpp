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
	freopen("SetIndex.inp" , "r" , stdin);
	freopen("SetIndex.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , m ;
namespace sub1
{
	int ans = 0 , a[25][25];
	vector<int> row , col;
	bool check()
	{
	
		if(col.size() == 0 || row.size() == 0) return false;
		int res = 0;
	//	for(auto x : row) cout << x << ' ';
	//	cout << endl;
	//	for(auto y : col) cout << y << ' ';
	//	cout << endl;
		for(auto x : row)
		  for(auto y : col)
		   res += a[x][y] ;
		//	cout << col.size() << ' ' << row.size() << ' ' << res << ' ' << '\n';
		if(res % 2 == 1) return true;
		return false;
	}
	
	void gen2(int t)
	{
			for(int i = 0 ; i <= 1 ; i++)
		{
		//	cout << t << '\n';
			if(i == 1) col.pb(t);
			if(t == m) 
			{
				//cout << "gen2" << col.size() << endl;
				if(check()) ans++;
			}
			else gen2(t + 1);
			if(i == 1) col.pop_back();
		}
	}
	void gen1(int t)
	{
		for(int i = 0 ; i <= 1;  i++)
		{
		//	cout << t << ' ';
			if(i == 1) row.pb(t);
			if(t == n) 
			{
			//	cout << "gen1" << row.size() << endl;
				gen2(1);
			}
			else gen1(t + 1);
			if(i == 1) row.pop_back();
		}
	}
	void solve()
	{
		for(int i = 1 ; i <= n ; i++) 
         for(int j = 1 ; j <= m ; j++)
          cin >> a[i][j];
        gen1(1);
        cout << ans;
	}
}
int main()
{
	file();
  cin >> n >> m;
  if(n + m <= 20) sub1::solve();
 
   
}

