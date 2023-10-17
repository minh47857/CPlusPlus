#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("mcows.inp" , "r" , stdin);
	freopen("mcows.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , ans , x , dem = 1 , t = 9;

int main() {
	file();
	cin >> n;
	// 1 9 9
	// 2 90 99
	// 3 900 999
	while(x * 10 + 9 <= n) {
		x = x * 10 + 9;
		ans += dem * t;
		t *= 10;
		dem++;
	}
	cout << ans + dem * (n - x);
	return 0;
}

