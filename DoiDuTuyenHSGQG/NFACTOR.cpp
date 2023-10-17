#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll d[N] , factor[N] , num[N][11] , n , a , b , t;
vector<ll> nt ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void snt() 
{
	ll dem = 0;
	d[1] = 1 , d[0] = 1 ;
    for(int i = 2; i * i <= 1e6; i++) 
         if(d[i] == 0)  for(int j = i * i; j <= 1e6; j += i)   d[j] = 1; 
         
         for (int i = 1 ; i <= 1e6 ; i++) if (d[i] == 0) nt.pb(i);
         
         for (auto x : nt) 
         	for (int j = x ; j <= 1e6 ; j += x) factor[j]++;
		 
	for (int i = 1 ; i <= 1e6 ; i++) 
	{
		for (int j = 0 ; j <= 10 ; j++) num[i][j] += num[i-1][j];
		if (factor[i] <= 10)	num[i][factor[i]]++;
	}
}
int main()
{
  file ();
  snt ();
  cin >> t ;
  while (t --)
  {
  	cin >> a >> b >> n;
  	cout << num[b][n] - num[a - 1][n] << '\n';
  }
}

