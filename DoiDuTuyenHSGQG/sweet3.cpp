#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 , inf = 1e15;
ll dem , n , f[11][N] , b , c , a , num[11] , t;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve()
{
	dem = 0;
	while (n != 0)
	{
		dem++;
		num[dem] = n % 10;
		n = n / 10;
	}
	memset(f , 0 , sizeof(f));
	f[0][0] = 1;
	
	for (int i = 0 ; i < dem ; i++)
	{
		for (int du = 0 ; du <= a + b + c - 1 ; du++)
		{
		   for (int x = 0 ; x <= 9 ; x++)
		   for (int y = 0 ; y <= 9 ; y++)
		   for (int z = 0 ; z <= 9 ; z++)
		   {
		   	if ((x * a + y * b + z * c + du) % 10 == num[i + 1]) f[i + 1][ (x * a + y * b + z * c + du) / 10] += f[i][du];
		   }
		}
	}
	cout << f[dem][0] << '\n';
}
int main()
{
	file();
	cin >> t;
 while (t--)
 {
 	cin >> n >> a >> b >> c;
 	solve();
 }
}

