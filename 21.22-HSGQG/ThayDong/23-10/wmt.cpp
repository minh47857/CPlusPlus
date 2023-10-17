#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e3 + 5 , inf = 1e9 + 7;

void file() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m;
ll ans = 0 , s[N][N];
vector<int> a[N];

ll solve(int u , int v) {
	int d = 0 , c = n;
	while(d <= c) {
		int g = (d + c) / 2;
		if(a[u][g] <= a[v][n - g + 1] && a[u][g + 1] >= a[v][n - g]) {
			return s[u][n] - 2 * s[u][g] + s[v][n] - 2 * s[v][n - g];
		}
		
		else {
			if(a[u][g + 1] <= a[v][n - g]) d = g + 1;
			else c = g - 1;
		}
	}
}

int main() {
	file();
  cin >> m >> n;
  for(int i = 1 ; i <= m ; i++) 
  	for(int j = 1 , x; j <= n ; j++) cin >> x , a[i].pb(x);
  for(int i = 1 ; i <= m ; i++) a[i].pb(0) , a[i].pb(inf) , sort(a[i].begin() , a[i].end());
  for(int i = 1 ; i <= m ; i++)
   for(int j = 1 ; j <= n ; j++)
    s[i][j] = s[i][j - 1] + a[i][j];
  for(int i = 1 ; i < m ; i++) 
   for(int j = i + 1 ; j <= m ; j++)
     ans += solve(i , j);
     cout << ans;
     return 0;
}
