#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("socdist1.inp" , "r" , stdin);
	freopen("socdist1.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , ans , d , c , g , a[N];

bool check(int D) {
	int res = 0;
	for(int i = 2 ; i <= m ; i++) {
		if(a[i] - a[i - 1] < D) return false;
		if((a[i] - a[i - 1]) / 3 >= D) res += 2;
		else if((a[i] - a[i - 1]) / 2 >= D) res += 1;
	}
	if((a[1] - 1) / 2 >= D) res += 2;
	else if(a[1] - 1 >= D) res += 1;
	if((n - a[m]) / 2 >= D) res += 2;
	else if(n - a[m] >= D) res += 1;
	return res >= 2;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		char x ; cin >> x;
		if(x == '1') a[++m] = i;
	}
	if(!m) {
		cout << n - 1;
		return 0;
	}
	c = n;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , d = g + 1;
		else c = g - 1;
	}
	cout << ans;
	return 0;
}

