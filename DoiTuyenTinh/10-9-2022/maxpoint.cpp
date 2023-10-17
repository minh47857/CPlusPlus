#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("maxpoint.inp" , "r" , stdin);
	freopen("maxpoint.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , f[N];
pi ans;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 , l , r ; i <= m ; i++) {
		cin >> l >> r;
		f[l]++;
		f[r + 1]--;
	}
	for(int i = 1 ; i <= n ; i++) {
		f[i] += f[i - 1];
		if(f[i] > ans.fi) ans = {f[i] , i};
	}
	cout << ans.se;
	return 0;
}

