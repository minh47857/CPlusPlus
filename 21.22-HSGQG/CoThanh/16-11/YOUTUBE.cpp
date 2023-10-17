#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("YOUTUBE.inp" , "r" , stdin);
	freopen("YOUTUBE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , m , a[N] , p[N][35];

int main() {
	file();
	cin >> n >> k >> m;
	m--;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 , x ; i <= k ; i++) cin >> p[i][0] ;
	for(int i = 1 ; i <= 30 ; i++)
	for(int j = 1 ; j <= k ; j++)
	p[j][i] = p[p[j][i - 1]][i - 1];
	for(int i = 1 ; i <= n ; i++) {
		int x = a[i] , S = m;
		for(int j = 30 ; j >= 0 ; j--) if((1 << j) <= S) S -= (1 << j) ,  x = p[x][j];
		cout << x << ' ';
	}
	return 0;
}


