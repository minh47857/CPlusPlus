#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e4 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("kcmax.inp" , "r" , stdin);
	freopen("kcmax.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int t , n , ans , d[N] , a[N];

int main() {
	file();
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		memset(d , 0 , sizeof(d));
		ans = 0;
		for(int i = 1 ; i <= n ; i++) {
			if(d[a[i]]) ans = max(ans , i - d[a[i]]);
			else d[a[i]] = i;
		}
		cout << ans << '\n';
	}
	return 0;
}

