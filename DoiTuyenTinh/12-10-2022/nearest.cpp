#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 2e9;

void file() {
	freopen("nearest.inp" , "r" , stdin);
	freopen("nearest.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , l = inf , a[N];
ll ans;
map<int , int> d;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 2 ; i <= n ; i++) l = min(l , a[i] - a[i - 1]);
	for(int i = 1 ; i <= n ; i++) ans += d[a[i] - l] , d[a[i]]++;
	cout << l << ' ' << ans;
	return 0;
}

