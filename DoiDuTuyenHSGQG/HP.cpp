#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e5 + 5 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m;
ll ans = 0 , sum = 0;
pi a[N];

int main() {
	file();
 cin >> n >> m;
 for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
 sort(a + 1 , a + n + 1);
 for(int i = 1 ; i <= n ; i++) {
 	ll tmp = 0;
 //	cout << a[i].fi << ' ' << a[i].se << sum << '\n';
 	tmp = a[i].se;
 	while(i < n && a[i].fi == a[i + 1].fi) {
 		tmp = (tmp + a[i + 1].se) % MOD;
 		i++;
	 }
	ans = (ans + tmp * sum) % MOD;
	sum = (sum + tmp ) % MOD;
 }
 cout << ans;
 return 0;
}

