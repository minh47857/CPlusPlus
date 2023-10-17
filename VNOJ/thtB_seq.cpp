#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , s[N] , ans = -inf;
map<ll , ll> f;

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
  for(int i = 1 ; i <= n ; i++) {
  	if(f.find(a[i]) != f.end()) 
	  {
	  	ans = max(ans , s[i] - s[f[a[i]]]);
	  	if(s[i - 1] < s[f[a[i]]]) f[a[i]] = i - 1;
	  }
	  else f[a[i]] = i - 1;
  }
  cout << ans;
  return 0;
}

