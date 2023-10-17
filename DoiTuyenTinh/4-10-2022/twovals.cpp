#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("twovals.inp" , "r" , stdin);
	freopen("twovals.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , l , ans , a[N];
pi x , y;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] != x.fi && a[i] != y.fi) {
			if(x.se > y.se) swap(x , y);
			l = x.se + 1;
			x = {a[i] , i};
		} 
		if(a[i] == x.fi) x.se = i;
		if(a[i] == y.fi) y.se = i;
		ans = max(ans , i - l + 1);
	}
	cout << ans;
	return 0;
}

