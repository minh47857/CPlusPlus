#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("Insert.inp" , "r" , stdin);
	freopen("Insert.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int ans = 0 , bit[N] , n , a[N];

void update(int u , int val) {
	for(int i = u ; i <= n ; i += (i & (-i))) bit[i] = max(bit[i] , val);
}

int get(int u) {
	int res = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i))) res = max(res , bit[i]);
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		int res = get(a[i]);
		update(a[i] , res + 1);
		ans = max(ans , res + 1);
	}
	cout << n - ans;
	return 0;
}


