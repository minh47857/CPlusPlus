#include<bits/stdc++.h>
using namespace std;

const int N = 6005;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int a , b , c , d, e , s[N][N] , best = 0;

int get(int u , int v , int x , int y) {
	return s[u][v] - s[u][y - 1] - s[x - 1][v] + s[x - 1][y - 1];
}

void solve () {
	for(int i = 1 ; i <= a ; i++) 
	  for(int j = 1 ; j <= b ; j++) 
	  for(int k = best + 1; k <= min(i , j) ; k++) {
	  	if(get(i , j , i - k + 1 , j - k + 1) <= e) best = k;
	  	else break;
	  }
	cout << best / d * d;	
}

int main() {
	file();
 cin >> a >> b >> c >> d >> e;
 for(int i = 1 , u , v ; i <= c ; i++) cin >> u >> v , s[u][v] = 1;
 for(int i = 1 ; i <= a ; i++)
   for(int j = 1 ; j <= b ; j++)
     s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
  solve();
  return 0;
}

