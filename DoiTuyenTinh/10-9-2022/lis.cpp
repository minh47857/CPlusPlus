#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("lis.inp" , "r" , stdin);
	freopen("lis.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , l , ans , a[N] , v[N] , f[N] , bit[N];

void update(int i , int val) {
	for( ; i <= n ; i += (i & (-i))) 
		bit[i] = max(bit[i] , val);
}

int get(int i) {
	int res = 0;
	for( ; i >= 1 ; i -= (i & (-i)))
		res = max(res , bit[i]);
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		f[i] = get(a[i] - 1) + 1;
		update(a[i] , f[i]);
	}
	l = get(n);
	cout << l << ' ';
	if(l == 1) {
		cout << n;
		return 0;
	}
	for(int i = n ; i >= 1 ; i--) {
		if(f[i] == l) {
			v[f[i]]++;
			continue;
		}
		if(v[f[i] + 1]) {
			v[f[i] + 1]-- , v[f[i]]++;
			if(f[i] == 1) ans++;
		}	
	}
	cout << ans;
	return 0;
}

