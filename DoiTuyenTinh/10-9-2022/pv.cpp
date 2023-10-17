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
	freopen("pv.inp" , "r" , stdin);
	freopen("pv.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N] , pre = -inf , ans;
vector<int> v;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++)
		if(a[i] > pre) pre = a[i] , ans++ , v.pb(i);
	cout << ans << '\n';
	for(auto i : v) cout << i << ' ';
	return 0;
}

