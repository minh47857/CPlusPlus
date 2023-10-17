#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("div.inp" , "r" , stdin);
	freopen("div.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , s , p , ans , a[N];

bool check() {
	ans = 0 , p = 0;
	for(int i = 1 ; i <= n ; i++) {
		p += a[i];
		if(p > s) return false;
		if(p == s) p = 0 , ans++;
	}
	return p == 0;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		s += a[i];
		if(check()) {
			cout << ans;
			return 0;
		}
	}
}

