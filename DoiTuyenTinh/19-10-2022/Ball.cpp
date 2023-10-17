#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;
int n, a[N];

void file() {
	freopen("Ball.inp" , "r" , stdin);
	freopen("Ball.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	int ans = 0;
	int val = a[1];
	for (int i = 2; i <= n; ++i) {
		if (a[i] > a[i - 1]) ans = max(ans, a[i] - val);
		else
			val = a[i];
	}
	val = a[1];
	for (int i = 2; i <= n; ++i) {
		if (a[i] < a[i - 1]) ans = max(ans, val - a[i]);
		else
			val = a[i];
	}
	cout << ans;
}

int main() {
	file();
	solve();
	return 0;
}

