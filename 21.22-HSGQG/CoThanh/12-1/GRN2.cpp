#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 2e3 + 5 , MOD = 111539786 , inf = 1e15;

void file()
{
	freopen("GRN2.inp" , "r" , stdin);
	freopen("GRN2.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , c[N][N] , f[N] , g[N] , ans = 0;
map<int , int> num;
vector<ll> diff;

ll solve(ll x) {
  multiset<int> s;
  map<int , int> d , vis;
  vector<int> Q;
  ll res = 1;
  for(int i = 1 ; i <= n ; i++) {
  	auto it = s.find(a[i] - x);
  	if(it != s.end()) {
  		s.erase(it) , d[a[i]]++;
  		if(!vis[a[i] - x]) Q.pb(a[i] - x);
  		vis[a[i] - x] = 1;
  		if(!vis[a[i]]) Q.pb(a[i]);
  		vis[a[i]] = 1 ;
	}
  	else s.insert(a[i]);
  }
  if(s.size()) return 0;
  
  if(x == 0) {
  	for(auto x : Q) res = (res * g[num[x] / 2]) % MOD;
  	return res;
  }
  
  for(int i = 0 ; i < Q.size() ; i++) {
  	if(i % 2) res = (res * f[num[Q[i]]]) % MOD;
  	else res = (res * c[num[Q[i]]][d[Q[i]]]) % MOD;
  }
  return res;
}

int main() {
	file();
  cin >> n;
  n = n * 2;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , num[a[i]]++;
  sort(a + 1 , a + n + 1);
  for(int i = 2 ; i <= n ; i++) diff.pb(a[i] - a[1]);
  
  f[0] = 1 , g[0] = 1;
  for(int i = 1 ; i <= n ; i++) f[i] = (f[i - 1] * i) % MOD;
  for(int i = 1 ; i <= n ; i++) g[i] = (2 * i - 1) * g[i - 1] % MOD;
  for(int i = 0 ; i <= n ; i++) {
  	c[i][0] = c[i][i] = 1;
  	 for(int j = 1 ; j <= i / 2 ; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  }
  diff.erase(unique(diff.begin() , diff.end()) , diff.end());
  for(auto x : diff) ans += solve(x);
  cout << ans;
  return 0;
}
