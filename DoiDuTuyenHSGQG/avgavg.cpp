#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , a[N] , s[N] , sum[N];
long double ans = 0;
int main() {
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
  for(int i = 1 ; i <= n ; i++) sum[i] = sum[i - 1] + i * (a[i] + a[n - i + 1]);
  for(int i = 1 ; i <= (n + 1) / 2 ; i++) {
  	int l = i , r = n - i + 1;
  	ll cur = sum[l - 1] + (s[r] - s[l - 1]) * l;
  //	cout << cur << ' ';
  	ans = ans + cur * 1.0 / i;
  }
  
  for(int i = n ; i > (n + 1) / 2 ; i--) {
  	int l = n - i + 1 , r = i;
  	ll cur = sum[l - 1] + (s[r] - s[l - 1]) * l;
 // 	cout << cur << ' ';
  	ans = ans + cur * 1.0 / i;
  }
  ans = ans * 2/ (n * 1.0 * (n + 1));
  cout << fixed << setprecision(6) << ans;
  return 0;
}

