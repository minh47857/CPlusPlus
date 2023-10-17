#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 998244353 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll l , r , k , mu[20];
int a[20];
pi f[20][1025][3][3];

int Bit(int x , int k)
{
	return (x >> k) & 1;
}

pi calc(int id , int mask , int ok , int check)
{
  if (id == 0) return {1 , 0};
  if (f[id][mask][ok][check].fi != -1) return f[id][mask][ok][check];
  ll cnt = 0 , num = __builtin_popcount(mask) , sum = 0  ;
  for (int i = 0 ; i <= max(ok * 9 ,  a[id]) ; i++)
   {
  	if(!Bit(mask , i) && num == k) continue;
  	int newmask = mask | (1 << i);
  	if (!check && i == 0) newmask--;
  	pi res = calc(id - 1 , newmask , ok | (i != a[id]) , check | (i != 0));
 // 	cout << 1 << ' ' << id << ' ' << i << ' ' << ok <<  ' ' << res.fi << ' ' << res.se << '\n';
  	cnt = (cnt + res.fi) % MOD;
  	sum = (sum + i * ((mu[id - 1] * res.fi) % MOD) + res.se) % MOD;
   }
  // cout << 2 << ' ' << id << ' ' << mask << ' ' << ok << ' ' << cnt << ' ' << sum << '\n';
  f[id][mask][ok][check] = make_pair(cnt , sum);
  return f[id][mask][ok][check];
}

ll solve(ll x)
{
	for (int i = 1 ; i <= 19 ; i++)
	  for (int j = 0 ; j < (1 << 10) ; j++)
	    for (int k = 0 ; k <= 1 ; k++)
	     for (int l = 0 ; l <= 1 ; l++)
	      f[i][j][k][l] = {-1 , 0};
	 for (int i = 1 ; i <= 19 ; i++ , x /= 10)  a[i] = x % 10 ;// cout << i << ' ' << a[i] << endl;
	 return calc(19 , 0 , 0 , 0).se;
}

int main()
{
	file();
  cin >> l >> r >> k;
  mu[0] = 1;
  for (int i = 1 ; i <= 18 ; i++) mu[i] = (mu[i - 1] * 10) % MOD;
  cout << (solve(r) - solve(l - 1) + MOD) % MOD;
  return 0; 
}

