#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("wood.inp" , "r" , stdin);
	freopen("wood.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , d = 0 , c = 1e9 , g , ans , a[N];

bool check(int x) {
	ll tmp = 0;
	for(int i = 1 ; i <= n ; i++)
		tmp += ((a[i] > x) ? (a[i] - x) : 0);
	return tmp >= m;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , d = g + 1;
		else c = g - 1;
	}
	cout << ans;
	return 0;
}

