#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll n  , b[21] , f[21][5][5][10];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll calc(int t , bool oka , bool okb , int nho)
{ 
//cout << i << ' ';
	if (t == 0)
	{
	//	cout << "?";
		if ((oka || okb) && nho == 0) return 1;
		else return 0;
	}
	if (f[t][oka][okb][nho] != -1) return f[t][oka][okb][nho];
	ll cnt = 0;
	for (int i = 0 ; i <= 9 ; i++)
	for (int j = 0 ; j <= 9 ; j++)
	{
		if ((i + j + nho) % 10 == b[t]) cnt += calc(t - 1 , oka | (i == 6) | (i == 8) , okb | (j == 6) | (j == 8) , (i + j + nho) / 10);
	}
	f[t][oka][okb][nho] = cnt;
	return cnt;
} 
bool check(ll y)
{
	//cout << "?";
	while (y != 0)
	{
	//	cout << y;
	//	cout << x % 10;
	 if (y % 10 == 8 || y % 10 == 6) return true;
	  y = y / 10;
    }
   return false;
}
void solve(ll x)
{
	ll tmp = x;
	memset(f , -1 , sizeof(f));
	for (int i = 19 ; i >= 1 ; i--) b[i] = x % 10 , x = x / 10;
	//cout << "?";
	ll res = calc(19 , 0 , 0 , 0);
	res /= 2;
    if ( check(tmp) ) res --;
    if ( tmp % 2 == 0 && check(tmp/2) ) res ++;
	cout << res << '\n'; 
}
int main()
{
	file();
   while (cin >> n) solve(n);
}

