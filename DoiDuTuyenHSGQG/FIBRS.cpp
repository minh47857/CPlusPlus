#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 3 , MOD = 1e9 +7 , inf = 1e15;
ll t , l , r , n;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
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
ll solve(ll x)
{
	Matrix ans ;
	ans.v[1][1] = ans.v[1][2] = ans.v[2][1] = 1 , ans.v[2][2] = 0;
	ans = pow(ans , x - 2);
	return (ans.v[1][1] + ans.v[1][2]) % MOD;
}
int main()
{
	file();
   cin >> t ;
   n = 2;
   while (t--)
   {
   	cin >> l >> r;
   cout << (solve(r + 2) - solve(l + 1) + MOD) % MOD << '\n';
   }
   return 0;
}

