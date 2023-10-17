#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("dream.inp" , "r" , stdin);
	freopen("dream.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , ans;
pi a[N];

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi , a[i].se = i;
	sort(a + 1 , a + n + 1);
	for(int i = 1 , l ; i <= n ; i++) {
		ans++;
		l = a[i].se;
		while(i < n && a[i + 1].fi == a[i].fi && a[i + 1].se - l < k) i++;
	}
	cout << ans;
	return 0;
}

