#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("ljutnja.inp" , "r" , stdin);
	freopen("ljutnja.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll m , n , s , tmp , ans , a[N];

int main() {
	file();
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , s += a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		tmp = min(a[i] , (s - m + n - i) / (n - i + 1));
		s -= a[i];
		m -= (a[i] - tmp);
		ans += tmp * tmp;
	}
	cout << ans;
	return 0;
}

