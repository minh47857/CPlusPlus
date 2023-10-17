#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 205 , MOD = 1e9 + 7 , inf = 1e9 + 7;

string s , t;
int n , m , dp[N][N][405];
vector<char> ans;

struct bracket {
	int fi , se , bal;
} trace[N][N][405];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> s >> t;
	n = s.size() , m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	memset(dp , 0x3f , sizeof(dp));
	dp[0][0][0] = 0;
	for(int i = 0 ; i <= n ; i++)
	  for(int j = 0 ; j <= m ; j++)
	  	for(int k = 0 ; k <= 400 ; k++) {
	  		//cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
	  		int nxi , nxj;
	  		if(i < n && s[i + 1] == '(') nxi = i + 1 ; else nxi = i;
			if(j < m && t[j + 1] == '(') nxj = j + 1 ; else nxj = j;
			if(dp[nxi][nxj][k + 1] > dp[i][j][k] + 1)   
				dp[nxi][nxj][k + 1] = dp[i][j][k] + 1 , trace[nxi][nxj][k + 1] = {i , j , k};
			if(k == 0) continue;
			if(i < n && s[i + 1] == ')') nxi = i + 1 ; else nxi = i;
			if(j < m && t[j + 1] == ')') nxj = j + 1 ; else nxj = j;
			if(dp[nxi][nxj][k - 1] > dp[i][j][k] + 1)   
				dp[nxi][nxj][k - 1] = dp[i][j][k] + 1 , trace[nxi][nxj][k - 1] = {i , j , k};
		}
	int res = 0;
    for(int i = 0 ; i <= 400 ; i++)
    	if(dp[n][m][i] + i < dp[n][m][res] + res) res = i;
    for(int i = 1 ; i <= res ; i++) ans.pb(')');
	int i = n , j = m , k = res;
	while(i || j || k) {
	//	cout << i << ' ' << j << ' ' << k << '\n';
		int nxi = trace[i][j][k].fi , nxj = trace[i][j][k].se , nxk = trace[i][j][k].bal;
		if(k < nxk) ans.pb(')');
		else ans.pb('(');
		i = nxi , j = nxj , k = nxk;
	}
	reverse(ans.begin() , ans.end());
	for(char x : ans) cout << x;
	return 0;
}

