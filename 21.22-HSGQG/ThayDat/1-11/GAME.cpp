#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , t , a[N] , ans;

void solve() {
	int Max = 0;
	cin >> n;
	ans = 0;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , ans = __gcd(ans , a[i]) , Max = max(Max , a[i]);
	ans = Max / ans  - n;
	if(ans % 2) cout << "DD" << '\n';
	else cout << "M" << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) {
	 solve();
	}
	return 0;
}

