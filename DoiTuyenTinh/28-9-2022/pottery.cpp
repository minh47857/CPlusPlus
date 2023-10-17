#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("pottery.inp" , "r" , stdin);
	freopen("pottery.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int T , n , m , d , c = 1e9 , g , a[N] , b[N];
ll res;

int main() {
	file();
	cin >> T;
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	cin >> m; 	
	for(int i = 1 ; i <= m ; i++) cin >> b[i];
	while(d <= c) {
		g = (d + c) / 2;
		ll s1 = 0 , s2 = 0;
		for(int i = 1 ; i <= n ; i++) s1 += g / a[i];
		for(int i = 1 ; i <= m ; i++) s2 += (T - g) / b[i];
		if(s1 <= s2) res = s1 , d = g + 1;
		else c = g - 1;
	}
	cout << res;
	return 0;
}

