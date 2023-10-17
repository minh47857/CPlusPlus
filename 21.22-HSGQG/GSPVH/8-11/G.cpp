#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 300 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("shortest.inp" , "r" , stdin);
	freopen("shortest.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , d[N][N];
vector<pi> ans;

bool check(int x , int y) {
	for(int i = 1 ; i <= n ; i++) 
	    if(i != x && i != y && d[x][i] + d[i][y] == d[x][y]) return false;
	return true;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	 for(int j = 1 ; j <= n ; j++)
	  cin >> d[i][j];
	for(int i = 1 ; i <= n ; i++) 
	  for(int j = i + 1 ; j <= n ; j++)
	    if(check(i , j)) ans.pb({i , j});
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x.fi << ' ' << x.se << ' ' << d[x.fi][x.se] << '\n';
	return 0;
}

