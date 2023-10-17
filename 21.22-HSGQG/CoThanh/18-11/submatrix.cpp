#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 305 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("submatrix.in" , "r" , stdin);
	freopen("submatrix.ok" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k , a[N][N] , d[N * N] , ans = 0;

bool check(int x , int y , int p) {
	vector<int> Back;
	int res = 0;
	for(int i = x - p + 1 ; i <= x ; i++)
	for(int j = y - p + 1 ; j <= y ; j++) {
		if(!d[a[i][j]]) res++ , d[a[i][j]] = 1 , Back.pb(a[i][j]);
	}
	for(auto i : Back) d[i] = 0;
	if(res <= k) return true;
	return false;
}

int main() {
	file();
	cin >> m >> n >> k;
	for(int i = 1 ; i <= m ; i++)
	for(int j = 1 ; j <= n ; j++)
	cin >> a[i][j];
	for(int i = 1 ; i <= m ; i++)
	for(int j = 1 ; j <= n ; j++)
    while(ans + 1 <= i && ans + 1 <= j && check(i , j , ans + 1)) ans++;
    cout << ans;
	
}


