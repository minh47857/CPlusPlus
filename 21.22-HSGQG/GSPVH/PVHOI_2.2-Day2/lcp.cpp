#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 5e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , c[N] , id;
ll dp[2 * N][N];
string s[N];

int lcp(string a , string b) {
	for(int i = 1 ; i < min(a.size() , b.size()) ; i++) 
		if(a[i] != b[i]) return i - 1;
	return min(a.size() , b.size()) - 1;
}

int calc(int l , int r) {
	if(l == r) return 0;
	int pos = l + 1;
	for(int i = l + 2 ; i <= r ; i++) 
		if(c[i] < c[pos]) pos = i;
	int x = calc(l , pos - 1);
	int y = calc(pos , r);
	id++;
	for(int i = 0 ; i <= pos - l ; i++)
		for(int j = 0 ; j <= r - pos + 1 ; j++)
			dp[id][i + j] = max(dp[id][i + j] , dp[x][i] + dp[y][j] + 1LL * i * j * c[pos]);
	return id;
}

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> s[i] , s[i] = ' ' + s[i];
	sort(s + 1 , s + n + 1);
	for(int i = 1 ; i < n ; i++) c[i + 1] = lcp(s[i] , s[i + 1]);
	cout << dp[calc(1 , n)][k];
	return 0;
}
