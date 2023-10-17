#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("fm.inp" , "r" , stdin);
	freopen("fm.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , a[N];
ll ans;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		int d = 1 , c = i - 1 , g , res = 0;
		while(d <= c) {
			g = (d + c) / 2;
			if(a[g] + a[i] <= m) res = g , d = g + 1;
			else c = g - 1;
		}
		ans += res;
	}
	cout << ans;
	return 0;
}

