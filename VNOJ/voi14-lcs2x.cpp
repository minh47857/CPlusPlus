#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 1505;

int t , n , m , a[N] , b[N] , ans = 0 , clis[N];

void solve() {
	ans = 0;
	memset(clis , 0 , sizeof(clis));
	 cin >> n >> m;
   for (int i = 1; i <= n ; i ++) cin >> a[i];
   for (int i = 1; i <= m ; i++) cin >> b[i];
   for (int i = 1; i <= n ; i++) {
   	int Max = 0;
   	for (int j = 1; j <= m ; j++) {
   		if(a[i] == 0 && a[i] == b[j]) {
   			int oldMax = Max;
   			Max = max(Max , clis[j]);
   			clis[j] = max(oldMax + 1 , clis[j]);
		}
		else {
   			if (a[i] == b[j]) clis[j] = max(Max + 1, clis[j]);
   			if (a[i] >= 2 * b[j]) Max = max(Max , clis[j]);
   		}
	} 
   }
   for (int i = 1; i <= m ; i++) ans = max( ans , clis[i]);
   cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> t;
	while(t--) solve();
}
