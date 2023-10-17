#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("A1_round2.inp" , "r" , stdin);
	freopen("A1_round2.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , q , n , ans , z , f[N][30];
string s;

bool check(int l , int p , int r) {
	int res = 0;
	for(int i = 0 ; i <= 25 ; i++) 
		res += abs(f[r][i] - f[p][i] - (f[p][i] - f[l - 1][i]));
	return res == 1;
}

void solve() {

	cin >> s >> q;
	ans = 0;
	n = s.size()  ,  s = ' ' + s;
	for(int i = 1 ; i <= n ; i++) {
		for(int c = 0 ; c <= 25 ; c++) f[i][c] = f[i - 1][c];
		f[i][s[i] - 'a']++;
	}
	while(q--) {
		int l , r;
		cin >> l >> r;
		if((r - l) % 2) continue;
		ans += (check(l , (r + l) / 2 , r) || check(l , (r + l) / 2 - 1 , r));
	}
	cout << "Case #" << ++z << ": " << ans << '\n';
}

int main() {
//	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

