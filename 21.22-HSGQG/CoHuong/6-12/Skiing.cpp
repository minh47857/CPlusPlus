#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("Skiing.inp" , "r" , stdin);
	freopen("Skiing.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , dp[N][5] , ans = 0 , bit1[N] , bit2[N];
pi a[N];

void update(int bit[] , int pos , int val) {
	for(int i = pos ; i <= N - 5 ; i += (i & (-i))) 
		bit[i] = max(bit[i] , val);
}

int get(int bit[] , int pos) {
	int res = 0;
	for(int i = pos ; i >= 1 ; i -= (i & (-i)))
		res = max(res , bit[i]);
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i].se >> a[i].fi;
	sort(a + 1 , a + n + 1 , greater<pi>());
	for(int i = 1 ; i <= n ; i++) {
		dp[i][0] = get(bit1 , a[i].se) + 1;
		dp[i][1] = get(bit2 , (N - 5) - a[i].se + 1) + 1;
		update(bit1 , a[i].se , dp[i][1]);
		update(bit2 , (N - 5) - a[i].se + 1 , dp[i][0]);
		ans = max({ans , dp[i][0] , dp[i][1]});
	}
	cout << ans;
	return 0;
}


