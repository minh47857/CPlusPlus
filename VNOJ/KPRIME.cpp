#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , k , s[N] , pos[N] , ans = 0;
bool d[N];
void sieve()
{
	d[1] = 1;
	for (int i = 2 ; i <= sqrt(n) ; i++)
	if (!d[i]) for (int j = i * i ; j <= n ; j += i ) d[j] = 1;
	for (int i = 1 ; i <= n ; i++) s[i] = s[i - 1] + 1 - d[i] , pos[s[i]] = i;
}
int main()
{
	file();
  cin >> n >> k;
  sieve();
  for (int i = 2 ; i <= n ; i++) 
  {
  	if (s[i] >= k) ans += (pos[s[i] - k] + 1);
  }
  cout << ans;
}

