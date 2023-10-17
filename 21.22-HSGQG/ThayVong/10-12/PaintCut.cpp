#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 105  , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("PaintCut.inp" , "r" , stdin);
	freopen("PaintCut.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct row {
	int minl , maxl , minr , maxr;
	bool operator < (const row&s) const {
		return maxl < s.maxl;
	}
};

int t , n , m , a[N][N] , minpre[N][N] , maxpre[N][N] , minsuf[N][N] , maxsuf[N][N];
pi Blue[N] , Red[N];
row x[N];

bool check(int k) {
	for(int i = 1 ; i <= n ; i++) 
		x[i] = {minpre[i][k] , maxpre[i][k] , minsuf[i][k + 1] , maxsuf[i][k + 1]};
	sort(x + 1 , x + n + 1);
	Blue[0] = {0 , 1e6};
	Red[n + 1] = {1e6 , 0};
	for(int i = 1 ; i <= n ; i++) 
		Blue[i] = {max(Blue[i - 1].fi , x[i].maxl) , min(Blue[i - 1].se , x[i].minr)} ;
	for(int i = n ; i >= 1 ; i--) 
		Red[i] = {min(Red[i + 1].fi , x[i].minl) , max(Red[i + 1].se , x[i].maxr)} ;
	for(int i = 1 ; i < n ; i++) { 
		bool ok = true;
		ok = ok & (Blue[i].fi < Red[i + 1].fi) & (Blue[i].se > Red[i + 1].se);
		if(ok) return true;
	}
	return false;
}

void solve() {
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	for(int i = 1 ; i <= n ; i++) {
		maxpre[i][0] = maxsuf[i][m + 1] = 0;
		minpre[i][0] = minsuf[i][m + 1] = 1e6;
		for(int j = 1 ; j <= m ; j++) {
			maxpre[i][j] = max(maxpre[i][j - 1] , a[i][j]);
			minpre[i][j] = min(minpre[i][j - 1] , a[i][j]);
		}
		for(int j = m ; j >= 1 ; j--) {
			maxsuf[i][j] = max(maxsuf[i][j + 1] , a[i][j]);
			minsuf[i][j] = min(minsuf[i][j + 1] , a[i][j]);
		}
	}
	bool ans = false;
	for(int k = 1 ; k < m ; k++) 	
		ans |= check(k);
	cout << ((ans) ? "YES\n" : "NO\n");	
}

int main() {
	file();
	cin >> t;
	while(t--) 
		solve();
	return 0;
}
