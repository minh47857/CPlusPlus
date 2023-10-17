#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("uspon.inp" , "r" , stdin);
	freopen("uspon.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , M , ans , a[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	M = a[1];
	for(int i = 2 ; i <= n ; i++) {
		if(a[i] > a[i - 1]) ans = max(ans , a[i] - M);
		else M = a[i];
	}
	cout << ans;
	return 0;
}

