#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("LISYS.inp" , "r" , stdin);
	freopen("LISYS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , s , d[N] , ans = 0;

int main() {
	file();
		cin >> m >> n >> s;
		int a[m + 5][n + 5];
		for(int i = 1 ; i <= m ; i++)
		 for(int j = 1 ; j <= n ; j++) 
		   cin >> a[i][j];
		for(int i = 1 , x ; i <= s ; i++) cin >> x , d[x]++;
		for(int i = 1 ; i <= m ; i++)
		 for(int j = 1 ; j <= n ; j++)
		  if((a[i][j] + d[i] + d[j + m]) % 3 == 0) ans++;
		cout << ans;
		return 0;
}

