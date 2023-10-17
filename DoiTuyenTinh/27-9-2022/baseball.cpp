#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("baseball.inp" , "r" , stdin);
	freopen("baseball.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N] , ans;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int x = 1 ; x <= n - 2 ; x++)
		for(int y = x + 1 ; y < n ; y++) {
			int l = a[y] - a[x];
			int d = y + 1 , c = n , g , res1 = -1 , res2 = -1;
			while(d <= c) {
				g = (d + c) / 2;
				if(a[g] - a[y] >= l) res1 = g , c = g - 1;
				else d = g + 1;
			}
			d = y + 1 , c = n;
			while(d <= c) {
				g = (d + c) / 2;
				if(a[g] - a[y] <= 2*l) res2 = g , d = g + 1;
				else c = g - 1;
			}
			if(res1 != -1 && res2 != -1) ans += res2 - res1 + 1;
	}
	cout << ans;
	return 0;
}

