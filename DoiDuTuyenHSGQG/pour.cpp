#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1<<16 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int v , n , m , p[25] , f[25][N] , ans = inf , a[5] , vis[25][N];
queue<pair<int , int>> Q;

int main() {
	file();
  cin >> v >> n >> m;
  p[0] = 0;
  for(int i = 1 ; i <= n ; i++) cin >> p[i];
  for(int i = 0 ; i <= n ; i++)
   for(int j = 0 ; j <= v ; j++) f[i][j] = inf;
  f[0][v] = 0 , vis[0][v] = 1;
  Q.push({0 , v});
  while(Q.size()) {
  	int t = Q.front().fi , x = Q.front().se;
  	Q.pop();
  	a[1] = p[t] , a[2] = x , a[3] = v - p[t] - x;
  	for(int i = 1 ; i <= 3 ; i++) 
	 for(int j = 1 ; j <= 3 ; j++) if(i != j)  
		for(int k = 0 ; k <= n ; k++) {
			if(p[k] < a[i]) {
			int nx1 = k , nx2 = a[j] + a[i] - p[k];
				if(vis[nx1][nx2]) continue;
				f[nx1][nx2] = f[t][x] + 1;
				vis[nx1][nx2] = 1;
				Q.push({nx1 , nx2});
			}
			
            if(a[i] >= p[k] - a[j] && p[k] > a[j]) {
            int nx1 = k , nx2 = a[i] + a[j] - p[k];
				if(vis[nx1][nx2]) continue;
				f[nx1][nx2] = f[t][x] + 1;
				vis[nx1][nx2] = 1;
				Q.push({nx1 , nx2});
			} 
        }
  }
  
  for(int i = 0 ; i <= n ; i++)
   for(int j = 0 ; j <= v ; j++)
    if(j == m || p[i] == m || v - j - p[i] == m) ans = min(ans , f[i][j]);
  cout << (ans == inf ? -1 : ans);
  return 0;
}

