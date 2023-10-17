#include<bits/stdc++.h>
#define pi pair<ll , ll>
#define pb push_back
#define fi first
#define se second
#define ll long long
const ll N = 25 , MOD = 1e9 + 9 , inf = 1e15;
ll n , m , k , d , adj[N][N] , f[150] , result = 0;
using namespace std;
void file()
{
     ios::sync_with_stdio();
	 cin.tie(0);
	 cout.tie(0);
}
struct Matrix
{
	ll v[N][N];
};
Matrix combine(Matrix a , Matrix b)
{
	Matrix res;
	for (int i = 1 ; i <= n ; i++)
    	for (int j  = 1 ; j <= n ; j++)
           res.v[i][j] = 0;
	for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++)
	for (int l = 1 ; l <= n ; l++)
	res.v[i][j] = (res.v[i][j] + a.v[i][l] * b.v[l][j]) % MOD;
	return res;
}
Matrix pow(Matrix a , ll b)
{
	if (b == 1) return a;
	Matrix t = pow(a , b / 2);
	t = combine(t , t);
	if (b % 2 == 0) return t ;
	return combine(t , a);
}
int BIT(int x , int k)
{
	return (x >> k) & 1;
}
int main()
{
	file();
	cin >> n >> m >> k >> d;
	if(d == 1)
	{
		if (k ==  1) cout << 1;
		else cout << 0;
		return 0;
	}
	for (int i = 1 ; i <= m ; i++) 
	{
		ll x , y;
		cin >> x >> y ;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	for (int mask = 0 ; mask < (1 << k) ; mask++)
	{
		  Matrix res , kq;
		ll ans = (1 << n) - 1;
		for (int i = 0 ; i < k ; i++) 	if (BIT(mask , i)) ans = ans ^ (1 << i);
		
		for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
        if (BIT(ans , i - 1) && BIT(ans , j - 1))res.v[i][j] = adj[i][j];
        else res.v[i][j] = 0;
        
        for (int i = 1 ; i <= n ; i++) 
		if (BIT(ans , i - 1)) kq.v[1][i] = 1 ;
        else kq.v[1][i] = 0;
        
        res = pow(res , d - 1);
        kq = combine(kq , res);
        for (int i = 1 ; i <= n ; i++) f[mask] = (f[mask] + kq.v[1][i]) % MOD;
        if (__builtin_popcount(mask) % 2 == 0) result = (result + f[mask]) % MOD;
        else result = (result - f[mask] + MOD ) % MOD;
	}
	cout << result;
	return 0;
}

