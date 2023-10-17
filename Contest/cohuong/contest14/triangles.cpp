#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const int N = 2e3 + 5;

void file() {
	freopen("triangles.inp" , "r" , stdin);
	freopen("triangles.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , h[N][N] , r[N][N] , l[N][N] , ans = 0;
char a[N][N];

void Pre() {
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= n ; j++) {
	  	if(h[i][j] > l[i][j - 1]) l[i][j] = l[i][j - 1] + 1;
	  	else l[i][j] = min(l[i][j - 1] , h[i][j] - 1) + 1;
	  }	  
}

void Suf() {
	for(int i = 1 ; i <= n ; i++)
	  for(int j = n ; j >= 1 ; j--) {
	  	if(h[i][j] > r[i][j + 1]) r[i][j] = r[i][j + 1] + 1;
	  	else r[i][j] = min(r[i][j + 1] , h[i][j] - 1) + 1;
	  }
}

void Solve() {
	for(int i = 1 ; i <= n ; i++) 
	  for(int j = 1 ; j <= n ; j++)
	    ans += min(r[i][j] , l[i][j]);
	cout << ans;
}

int main() {
	file();
   cin >> n;
   for(int i = 1 ; i <= n ; i++) 
     for(int j = 1 ; j <= n ; j++)
       cin >> a[i][j];
       
    for(int i = 1 ; i <= n ; i++) 
	  for(int j = 1 ; j <= n ; j++)
	    if(a[i][j] == '#') h[i][j] = h[i - 1][j] + 1;
	    else h[i][j] = 0;
	
	Pre();
	Suf();
	Solve();
	return 0;
}
