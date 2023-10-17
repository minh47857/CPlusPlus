#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("truck.inp" , "r" , stdin);
	freopen("truck.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int  n , m , d , c = 1e9 , g , res , a[N];

bool check(int x) {
	int s = 0 , p = 1;
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] + s <= x) s += a[i];
		else s = a[i] , p++;
	}
	return (p <= m);
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , d = max(a[i] , d);
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) res = g , c = g - 1;
		else d = g + 1;
	}
	cout << res;
	return 0;
}
 
