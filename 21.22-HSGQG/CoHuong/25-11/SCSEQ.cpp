#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("SCSEQ.inp" , "r" , stdin);
	freopen("SCSEQ.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , s[N] , a[N] , P , ans = -inf;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
	for(ll i = 1 ; i <= n ; i++) {
		P = max(P , 1LL * 2 * s[i - 1] + (i - 1) * k);
		ll res = s[n] - 1LL * 2 * s[i] - i * k + P;
		ans = max(ans , res);
	}
	cout << ans;
}

