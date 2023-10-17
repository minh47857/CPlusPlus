#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e4 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("xoakpt.inp" , "r" , stdin);
	freopen("xoakpt.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , n , k , res , d[N];

void solve() {
	memset(d , 0 , sizeof(d));
	res = 0;
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) cin >> x , d[x]++;
	cin >> k;
	for(int i = 1 ; i <= n ; i++) res += max(d[i] - 1 , 0);
	if(k <= res) cout << n - res << '\n';
	else cout << n - k << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

