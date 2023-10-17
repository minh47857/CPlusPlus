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
//	freopen("sokhach.inp" , "r" , stdin);
//	freopen("sokhach.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , a[N] , b[N] , ans , l = 1 , r;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= m ; i++) cin >> b[i];
	sort(a + 1 , a + n + 1);
	sort(b + 1 , b + m + 1);
	r = m / 2 + 1;
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] <= b[l]) continue;
		while(r < m && a[i] >= b[r]) r++;
		if(a[i] < b[r]) ans++ , r++ , l++;
		if(r > m || l > m / 2) break;
	}
	cout << ans;
	return 0;
}

