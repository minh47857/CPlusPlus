#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 25 , MOD = 1e9 +7 , inf = 1e15;
ll n , m , c[N][N] , bac[N] , num = 0 , res , f[1 << 22] ;
vector <ll> v;
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
ll cal( int t)
{
	if (t == 0) return 0;
	if ( f[t] ) return f[t];
	ll best = inf ;
	for (int i = 0 ; i < v.size() ; i++)
	{
		for (int j = i + 1 ; j < v.size() ; j++)
		{
			if (v[i] == v[j]) continue;
		ll tmp = inf;
		if (BIT(t , i) && BIT(t , j))	tmp = cal(t ^ (1 << i) ^ (1 << j)) + c[v[i]][v[j]];
		best = min(best , tmp)	;
		}
	}
	f[t] = best ;
	return best;
}
int main()
{
	file();
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++)
	   c[i][j] = inf;
    for (int i = 1 ; i <= m ; i++)
    {
    	ll u , v , cc;
    	cin >> u >> v >> cc ;
    	bac[u] ++;
    	bac[v] ++;
    	c[u][v] = min(c[u][v] , cc);
    	c[v][u] = min(c[v][u] , cc);
    	res += cc;
	}
for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( c[i][j] > c[i][k] + c[k][j] )
                    c[i][j] = c[i][k] + c[k][j];
                    
     for (int i = 1; i <= n; i++) if( bac[i] % 2 == 1 ) v.pb(i);      
		  
	
    int check = 1;
    for (int i = 1; i <= n; i ++)
	{
        if ( bac[i] > 0 && c[1][i] == inf )
            check = 0;
    }

    if ( !check )
	{
        cout << -1;
        return 0;
    }
	cout << res + cal((1<<(v.size()))-1);
}
