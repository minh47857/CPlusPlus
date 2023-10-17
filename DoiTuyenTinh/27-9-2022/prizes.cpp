#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 2e5 + 5 , MOD = 1e9 + 7;
ll inf = 1e18;

void file() {
	freopen("prizes.inp" , "r" , stdin);
	freopen("prizes.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k;
ll s[N] , pre[N] , suf[N] , ans = inf;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 , x ; i <= n ; i++) 
		cin >> x , s[i] = s[i - 1] + x;
	memset(pre , -0x3f , sizeof(pre));
	memset(suf , -0x3f , sizeof(suf));
	for(int i = k ; i <= n ; i++) pre[i] = max(pre[i - 1] , s[i] - s[i - k]);
	for(int i = n - k + 1 ; i >= 1 ; i--) suf[i] = max(suf[i + 1] , s[i + k - 1] - s[i - 1]);
	for(int i = 1 ; i <= n - k + 1 ; i++) 
		ans = min(ans , max(pre[i - 1] , suf[i + k])) ;
	cout << ans;
	return 0;
}

