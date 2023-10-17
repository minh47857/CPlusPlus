#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 51 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll n , k , sum = 0 ;
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
int main()
{
	file();
  cin >> n >> k;
  Matrix r , ans;
  	for (int i = 1 ; i <= n ; i++)
    for (int j = 1 ; j <= n ; j++)
         r.v[i][j] =  ans.v[i][j] = 0;
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= n ; j++)
  	cin >> r.v[i][j];
  for (int i = 1 ; i <= n ; i++) ans.v[1][i] = 1;
   r = pow(r , k);
   r = combine(ans , r);
  for (int i = 1 ; i <= n;  i++) sum = (sum + r.v[1][i]) % MOD;
  cout << sum;
  return 0;
}

