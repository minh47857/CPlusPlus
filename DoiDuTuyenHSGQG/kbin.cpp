#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 60, MOD = 1234567;
ll c[N][N] , n , k , dp[N][N] , dem = 0 , res = 0 , ans = 0 , Pow2[N];
vector <ll> prime , q;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void snt()
{
	for  (int  i = 2 ; i <= 50 ; i++)
	{
		bool check = true;
		for (int j = 2 ; j <= sqrt(i) ; j++ ) if (i % j == 0) { check = false ; break ;};
		if (check) prime.pb(i);
	}	
}
ll tinh (int x , int k)
{
  ll d[N] , res = 1;
  memset ( d , 0 , sizeof (d));
	for (int i = x ; i > x - k; i--) 
	{
		int num = i;
		for (auto j : prime)
		{
			while (num % j == 0)
			{
				d[j]++;
				num = num / j;
			}
		}
	}
	for (int i = 2 ; i <= k ; i++)
	{
		int num = i;
		for (auto j : prime)
		{
			while (num % j == 0)
			{
				d[j]--;
				num = num / j;
			}
		}
	}
    for (auto x : prime ) 
    	for (int i = 1 ; i <= d[x] ; i++) res = (res * x) % MOD;
    return res;
}
int main()
{
	file();
	cin >> n >> k;
 /*  snt();
   Pow2[0] = 1;
   for (int i = 1;  i < N ; i++)
   {
     Pow2[i] =  (Pow2[i - 1] * 2 ) % MOD;
    for (int j = 0 ; j <= i / 2  ; j++)
	 c[i][j] = c[i][i - j] = tinh(i , j) ;
   }
	 dp[1][1] = 1 , c[0][0] = 1;*/
	 
  while (n > 0)
  {
  	q.pb(n % 2);
  	n = n / 2;
  }
	 c[0][0] = 1 , Pow2[0] = 1;
    for (ll i = 1; i <= 54; i ++){
     Pow2[i] =  (Pow2[i - 1] * 2 ) % MOD;
        c[i][0] = 1;
        for (int j = 1; j <= min(i, k); j ++)
            c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % MOD ;
    }

    for (ll i = 1; i <= q.size(); i ++)
        for (int j = 1; j <= min(i, k); j ++)
            dp[i][j] = ( dp[i-1][j] * 2 + dp[i-1][j-1] * 2 + c[i-1][j-1] ) % MOD ;

  reverse(q.begin() , q.end());
  /* for (ll i = 2 ; i < q.size() ; i++)
   	for (int j = 1 ; j <= min(i , k) ; j++)
   		dp[i][j] = (dp[i - 1][j] * 2 + dp[i - 1][j - 1] * 2 + c[i - 1][j - 1] ) % MOD;*/
	
  res = 0;
   for (int i = 0 ; i < q.size() ; i++)
   {
   	 if (q[i] == 1) 
		{
			ans = (ans + dp[q.size() - i - 1][k - dem] + res * c[q.size() - i - 1][k - dem]) % MOD;
			res = (res + Pow2[q.size() - i -  1] ) % MOD;
			dem ++;
			if (dem > k) break;
		}
   }
   if (dem == k ) ans += res;
   cout << ans % MOD;
   return 0;
}

