#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("timsko.inp" , "r" , stdin);
	freopen("timsko.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , k , ans;

int main() {
	file();
	cin >> m >> n >> k;
	for(int i = 0 , nn , nm ; i <= min(m , k) ; i++) {
		if(n < k - i) continue;
		nm = m - i;
		nn = n - k + i;
		ans = max(ans , min(nm / 2 , nn));
	}
	cout << ans;
	return 0;
}

