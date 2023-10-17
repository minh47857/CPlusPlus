#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("tamgiac.inp" , "r" , stdin);
	freopen("tamgiac.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N] , b[N] , c[N] , ans;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) cin >> b[i];
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	sort(a + 1 , a + n + 1);
	sort(b + 1 , b + n + 1);
	sort(c + 1 , c + n + 1);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++) {
			int l = abs(a[i] - b[j]) , r = a[i] + b[j] , dd , cc , g , res1 = -1 , res2 = -1;
			dd = 1 , cc = n;
			while(dd <= cc) {
				g = (dd + cc) / 2;
				if(c[g] > l) res1 = g , cc = g - 1;
				else dd = g + 1;
			}
			dd = 1 , cc = n;
			while(dd <= cc) {
				g = (dd + cc) / 2;
				if(c[g] < r) res2 = g , dd = g + 1;
				else cc = g - 1;
			}
			if(res1 != -1 && res2 != -1) ans += (res2 - res1 + 1);
		}
	cout << ans;
	return 0;
}

