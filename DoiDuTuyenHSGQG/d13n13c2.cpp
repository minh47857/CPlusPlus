#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll f[20][15][5] , x , y; 
int b[20];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll calc(int i , int c , bool ok)
{
	if (i > 16) return 1;
	if (f[i][c][ok] != -1) return f[i][c][ok];
	ll cnt = 0;
	for (int s = 0 ; s <= max(ok * 9 , b[i]) ; s++)
	{
		if (c * 10 + s != 13) cnt += calc(i + 1 , s , ok | (s < b[i]));
	}
	f[i][c][ok] = cnt;
	return cnt;
}
ll solve(ll n)
{
	if (n == -1) return 0;
	memset(b , 0 , sizeof(b));
	for (int i = 16 ; i >= 1 && n != 0 ; i--) b[i] = n % 10 , n = n / 10;
  	memset(f , -1 , sizeof(f));
  	return calc(1 , 0 , 0);
}
int main()
{
	file();
  while (cin >> x >> y)
  {
  	x--;
    cout << solve(y) - solve(x) << '\n';
  } 
}

