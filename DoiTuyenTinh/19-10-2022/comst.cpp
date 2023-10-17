#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , string>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("comst.inp" , "r" , stdin);
	freopen("comst.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

string s , t;
int n , m , dp[N][N];
pi ans;

int main() {
	file();
	cin >> s >> t;
	n = s.size() , m = t.size();
	s = ' ' + s , t = ' ' + t;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) 
			if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
	for(int i = 1 ; i <= n ; i++) {
		int tmp = 0;
		for(int j = 1 ; j <= m ; j++) tmp = max(tmp , dp[i][j]);
		if(tmp == ans.fi) ans.se = min(ans.se , s.substr(i - tmp + 1 , tmp));
		if(tmp > ans.fi) ans.fi = tmp , ans.se = s.substr(i - tmp + 1 , tmp);
	}
	cout << ans.fi << '\n' << ans.se;
	return 0;
}

