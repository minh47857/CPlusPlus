#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("divisor.inp" , "r" , stdin);
	freopen("divisor.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , ans , a[N] , f[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		f[i] = 1;
		for(int j = 1 ; j < i ; j++) if(a[i] % a[j] == 0) f[i] = max(f[i] , f[j] + 1);
		ans = max(ans , f[i]);
	}
	cout << ans;
	return 0;
}

