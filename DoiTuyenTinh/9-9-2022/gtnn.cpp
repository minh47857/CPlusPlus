#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 2e9 + 7;

void file() {
	freopen("gtnn.inp" , "r" , stdin);
	freopen("gtnn.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans = INT_MAX , a[N] , b[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) cin >> b[i];
	sort(a + 1 , a + n + 1);
	sort(b + 1 , b + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		int d = 1 , c = n , g , res = -1;
		while(d <= c) {
			g = (d + c) / 2;
			if(a[i] + b[g] >= 0) res = g , c = g - 1;
			else d = g + 1;
		}
		if(res == -1) continue;
		ans = min(ans , abs(a[i] + b[res]));
		if(res > 1) ans = min(ans , abs(a[i] + b[res - 1]));
	}
	cout << ans;
	return 0;
}

