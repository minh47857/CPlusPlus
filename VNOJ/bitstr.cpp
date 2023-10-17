#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 1e6 +7  , M = 105;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int f[3][M][N] , n , k , mu[N];
int calc(int i , int numk , bool ok)
{
   if (i == n)
   {
   	if (ok) return 1;
   	return 0;
   }
   if(f[ok][numk][i] != -1) return f[ok][numk][i];
   if (ok) return mu[n - i];
   int cnt = calc(i + 1 , 0 , ok) + calc(i + 1 , numk + 1 , ok | (numk + 1 >= k));
   if (cnt >= MOD) cnt -= MOD;
   f[ok][numk][i] = cnt;
   return cnt;
}
int main()
{
	file();
  cin >> n >> k;
  memset(f , -1 , sizeof(f));
  mu[0] = 1;
  for (int i = 1 ; i <= n ; i++) mu[i] = (mu[i - 1] * 2) % MOD;
  cout << calc(0 , 0 , 0);
  return 0;
}

