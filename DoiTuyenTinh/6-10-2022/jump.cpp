#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("jump.inp" , "r" , stdin);
	freopen("jump.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , P , suf[N] , ans , l;
pi a[N];

int main() {
	file();
	cin >> n >> P;
	for(int i = 1 , x ; i <= n ; i++) cin >> x , a[i] = {x , i};
	sort(a + 1 , a + n + 1);
	for(int i = n ; i >= 1 ; i--) suf[i] = max(a[i].se , suf[i + 1]);
	for(int i = 1 ; i <= n ; i++) {
		while(l < n && a[l].fi - a[i].fi < P) l++;
		if(a[l].fi - a[i].fi >= P && suf[l] > a[i].se) ans = max(ans , suf[l] - a[i].se);
	}
	cout << ans;
	return 0;
}

