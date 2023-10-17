#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 7;

void file() {
	freopen("bomb.inp" , "r" , stdin);
	freopen("bomb.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int ans = 0 , s[N][N] , n , m , a[N][N];

bool check(int x , int y) {
	if(a[x][y] == -1) return true;
	if(((s[x - 1][y] + s[x + 1][y] + s[x][y - 1] + s[x][y + 1]) % 2) == a[x][y]) return true;
	return false;
}

bool mine() { 
	for(int i = 1 ; i <= m ; i++) if(!check(n , i)) return false;
	return true;
}

void Gen(int u , int v) {
	for(int i = 0 ; i <= 1 ; i++) {
		s[u][v] = i;
		if(u > 1 && !check(u - 1 , v)) 	continue;
		if(u == n && v == m) ans += mine() ;
		else {
			if(v == m) Gen(u + 1 , 1);
			else Gen(u , v + 1);
		}
		s[u][v] = 0;
	}
}

int main() {
	file();
  cin >> n >> m;
  for(int i = 1 ; i <= n ; i++) 
   for(int j = 1 ; j <= m ; j++)
    cin >> a[i][j];
  Gen(1 , 1);
   cout << ans;
   return 0;
}

