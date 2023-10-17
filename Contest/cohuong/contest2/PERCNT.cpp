#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 3001 , MOD = 1e9 +7 , inf = 1e15;

void file()
{
	freopen("PERCNT.inp" , "r" , stdin);
	freopen("PERCNT.out" , "w" , stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
}
 int n , k;
 
namespace sub1
{
	int d[15] , ans = 0 , s[15] , a[15];
	void gen(int t)
	{
		for (int i = 1 ; i <= n ; i++)
		{
			if (d[i] == 1) continue;
			d[i] = 1;
			a[t] = i;
			s[t] = s[t - 1];
			if (a[t] < a[t - 1]) s[t]++;
			
		
			
			if (t == n) 
			{
		//	for (int j = 1 ; j <= n ; j++) cout << a[j] << ' ';
		//	cout << endl;
				if (s[t] == k) ans = (ans + 1) % MOD;
			}
			else gen(t + 1);
			d[i] = 0;
		}
	}
	
	void solve()
	{
		a[0] = 1e9 , s[0] = 0;
		gen(1);
		cout << ans << '\n';
	}
}
namespace sub3
{
    ll f[N][N];

    void solve()
	{
        f[0][0] = 1;
       for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j <= min(k - 1 , i) ; j++)
        {
        	f[i + 1][j] = (f[i + 1][j] + f[i][j] * (j + 1)) % MOD;
        	f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * (i + 1 - j - 1))% MOD;
		}

        cout << f[n][k-1] << '\n';
    }
}
int main()
{
	file();
   cin >> n >> k;
   if (n <= 10) sub1::solve() ;
   if (n > 10 && n <= 3000) sub3::solve();
   return 0;
}

