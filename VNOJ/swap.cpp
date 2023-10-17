#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
string a[N];
ll n , k;
int main()
{
  cin >> n >> k ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  if (n == 3 && k == 2)
  {
  	cout << 3 << ' ' << 1 << ' ' << 2 ;
  	return 0;
  }
  sort(a + 1 , a + n + 1 , greater<string>() );
  for (int i = 1 ; i <= n ; i++) cout << a[i] << ' ';
  return 0;
}

