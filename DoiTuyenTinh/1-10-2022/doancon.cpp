#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("doancon.inp" , "r" , stdin);
	freopen("doancon.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , f[N];
pi ans;

bool check(int x) {
	if(x == 1) return false;
	for(int i = 2 ; i <= sqrt(x) ; i++) 
		if(x % i == 0) return false;
	return true;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		f[i] = (check(a[i]) ? f[i - 1] + 1 : 0);
		ans = max(ans , {f[i] , i});
	}
	if(!ans.fi) cout << -1;
	else {
		cout << ans.fi << '\n';
		for(int i = ans.se - ans.fi + 1 ; i <= ans.se ; i++) 
			cout << a[i] << ' ';
	}
}

