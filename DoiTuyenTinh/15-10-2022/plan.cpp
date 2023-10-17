#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 5e2 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("plan.inp" , "r" , stdin);
	freopen("plan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , k;
ll s[N][N] , a[N * N];

int main() {
	file();
	cin >> m >> n >> k;
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++) {
			int x ; cin >> x; 
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x; 
			a[n * (i - 1) + j] = s[i][j];
		}
	n *= m;
	sort(a + 1 , a + n + 1);
	while(k--) {
		int d , c , g , res1 = -1 , res2 = -1;
		ll x , y ; cin >> x >> y;
		d = 1 , c = n;
		while(d <= c) {
			g = (d + c) / 2;
			if(a[g] >= x) res1 = g , c = g - 1;
			else d = g + 1;
		}
		d = 1 , c = n;
		while(d <= c) {
			g = (d + c) / 2;
			if(a[g] <= y) res2 = g , d = g + 1;
			else c = g - 1;
		}
		if(res1 == -1 || res2 == -1 || res1 > res2) cout << -1 << '\n';
		else {
			if(a[res1] - x <= y - a[res2]) cout << a[res1] << '\n';
			else cout << a[res2] << '\n';
		}
	}
	return 0;
}

