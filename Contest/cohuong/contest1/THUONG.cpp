#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e15;
 string str ;
 ll n , Pow[N] , Hash1[N] , Hash2[N] , k , base = 31;
void file()
{
	freopen("THUONG.inp" , "r" , stdin);
	freopen("THUONG.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll get1(int x , int y )
 {
 	return ( Hash1[y] - Hash1[x - 1] * Pow [y - x + 1] + MOD * MOD ) % MOD;
 }
 
 ll get2(int x , int y)
 {
 	return (Hash2[x] - Hash2[y + 1] * Pow[y - x + 1] + MOD * MOD ) % MOD;
 }
int main()
{
	file();
  cin >> str ;
  n = str.size();
  Pow[0] = 1;
  for (int i = 1 ; i <= n ; i++) Pow[i] = (Pow[i - 1] * base) % MOD; 
  for (int i = 1 ; i <= n ; i++) Hash1[i] = (Hash1[i - 1] * base + str[i - 1] - 'a' + 1) % MOD ;
  for (int i = n ; i >= 1 ; i--) Hash2[i] = (Hash2[i + 1] * base + str[i - 1] - 'a' + 1) % MOD ;
  
  cin >> k;
  while (k --)
  {
  	int l , r;
  	cin >> l >> r;
  	if (get1(l , r ) == get2(l , r)) cout << 1 << '\n';
  	else cout << -1 << '\n';
  }
  return 0;
}

