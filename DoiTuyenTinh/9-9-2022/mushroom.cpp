#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("mushroom.inp" , "r" , stdin);
	freopen("mushroom.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , ans = -inf , s;
pi a[N];

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].se >> a[i].fi;
	sort(a + 1 , a + n + 1);
	int l = 1;
	for(int i = 1 ; i <= n ; i++) {
		s += a[i].se;
		while(a[i].fi - a[l].fi > 2 * k) s -= a[l].se , l++;
		ans = max(ans , s);
	}
	cout << ans;
	return 0;
}

