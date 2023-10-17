#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k , n , m , q ;
pi E[N] , A[N] , Z[N];

void solve() {
	int ans = 0 , j = 1;
	multiset<int> Q;
	for(int i = k ; i <= k + n - 1 ; i++)  Z[i - k + 1] = A[i];
	sort(Z + 1 , Z + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		while(j <= n && (Z[j].fi < E[i].fi)) Q.insert(Z[j++].se);
		if(Q.empty() || *Q.begin() >=  E[i].se) continue;
		auto it = Q.lower_bound(E[i].se) ;
		it--;
		Q.erase(it);
		ans++;
	}
	cout << ans << '\n';
}

int main() {
  cin >> n >> m >> q;
  for(int i = 1 ; i <= n ; i++) cin >> E[i].fi;
  for(int i = 1 ; i <= n ; i++) cin >> E[i].se;
  for(int i = 1 ; i <= m ; i++) cin >> A[i].fi;
  for(int i = 1 ; i <= m ; i++) cin >> A[i].se;
  sort(E + 1 , E + n + 1);
  while(q--) {
  	cin >> k;
  	solve();
  }
  return 0;
}

