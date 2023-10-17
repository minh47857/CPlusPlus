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
ll n , a[N] , ans2 = 0 , ans5 = 0;
int calc(int x , int k)
{
	int dem = 0;
	while (x % k == 0) dem++ , x /= k;
	return dem;
}
int main()
{
	file();
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  for (int i = 1 ; i <= n ; i++)
  {
  	ans2 += calc(a[i] , 2);
  	ans5 += calc(a[i] , 5);
  }
  cout << min(ans2 , ans5);
}

