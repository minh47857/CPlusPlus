#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pi pair<int , int>
#define pb push_back

using namespace std;
const int N = 1e7 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("ddmax.inp" , "r" , stdin);
	freopen("ddmax.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;
ll s[N];
pi a[N] , ans;

int main() {
	file();
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) cin >> x , s[i] = s[i - 1] + x;
	for(int i = 1 ; i <= n ; i++) a[i] = {s[i] , i};
	sort(a , a + n + 1);
	for(int i = 0 , l = n ; i <= n ; i++) {
		int newl = n;
		ans = max(ans , {a[i].se - l , l + 1});
		newl = min(newl , a[i].se);
		while(i < n && a[i].fi == a[i + 1].fi) {
			i++;
			ans = max(ans , {a[i].se - l , l + 1});
			newl = min(newl , a[i].se);
		}
		l = min(l , newl);
	}
	if(!ans.fi) cout << 0 << '\n' << 0 << '\n' << 0;
	else cout << ans.fi << '\n' << ans.se << '\n' << ans.se + ans.fi - 1;
	return 0;
}

