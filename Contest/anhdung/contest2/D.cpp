#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , ans = 0;

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  for(int i = 1 ; i <= n ; i++) {
  	int w = 0;
  	if(a[i] >= a[i - 1] && i > 1) w++;
  	if(a[i] > a[i + 1] && i < n) w++;
  	ans += (w * a[i]);
  }
  cout << ans;
}

