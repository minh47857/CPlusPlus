#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("party.inp" , "r" , stdin);
	freopen("party.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , a[N] , f[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , f[i] = inf;
	f[0] = -inf;
	for(int i = 1 ; i <= n ; i++) {
		int d = 0 , c = i - 1 , g , res;
		while(d <= c) {
			g = (d + c) / 2;
			if(f[g] < a[i]) res = g , d = g + 1;
			else c = g - 1;
		}
		f[res + 1] = min(f[res + 1] , a[i]);
		ans = max(ans , res + 1);
	}
	cout << ans;
	return 0;
}

