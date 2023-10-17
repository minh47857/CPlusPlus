#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 55 , MOD = 1e9 + 7 , inf = 1e15;
ll  n , k , b[N] , result = 1 , kqq = 1;
struct Matrix
{
	ll v[N][N];
};
Matrix combine(Matrix a , Matrix b)
{
	Matrix res;
	for (int i = 1 ; i <= k ; i++)
    	for (int j  = 1 ; j <= k ; j++)
           res.v[i][j] = 0;
	for (int i = 1 ; i <= k ; i++)
	for (int j = 1 ; j <= k ; j++)
	for (int l = 1 ; l <= k ; l++)
	res.v[i][j] = (res.v[i][j] + a.v[i][l] * b.v[l][j]) % (MOD - 1);
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
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll sqr(ll x)
{
	return (x * x) % MOD;
}
ll poww (ll a , ll b)
{
	if (b == 0) return 1;
	if (b % 2 == 0) return sqr(poww(a , b / 2));
	return (sqr(poww(a , b / 2)) * a) % MOD;
}
int main()
{
	file();
  	cin >> n >> k;
  	for (int i = 1 ; i <= k ; i++) cin >> b[i];
  	if (n <= k)
  	{
  		cout << b[n] << '\n';
  		return 0;
	}
  	Matrix ans , res , kq;
  	 for (int i = 1 ; i <= k ; i++)
    	for (int j  = 1 ; j <= k ; j++)
           ans.v[i][j] = 0 , res.v[i][j] = 0;
	
  	for (int i = 1 ; i <= k ; i++) ans.v[i][1] = 1;
  	for (int i = 2 ; i <= k ; i++) ans.v[i - 1][i] = 1;
  	ans = pow(ans , n - k);
  	for (int i = 1 ; i <= k ; i++) res.v[i][i] = 1;
  	kq = combine(res , ans);
    for (int i = 1 ; i <= k ; i++) result = poww(b[k - i + 1] , kq.v[i][1])  , kqq =( kqq * result) % MOD ; // cout << b[k - i + 1] << ' ' <<  kq.v[i][1] <<' '<<poww(b[k - i + 1] , kq.v[i][1])<< endl;
    cout << kqq ;
    return 0;
}


