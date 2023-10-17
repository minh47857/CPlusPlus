#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>

const int N = 205 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	 freopen("MAP.inp" , "r" , stdin);
	 freopen("MAP.out" , "w" , stdout);
	 ios::sync_with_stdio(0);
	 cin.tie(0) ; cout.tie(0);
}

int n , w , h , ans[N][N];
pi a[N];
vector<int> row[N];

int main() {
	file();
	cin >> n >> w >> h;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i].fi >> a[i].se;
	a[n + 1] = a[1];
	for(int i = 1 , r , l ; i <= n ; i++) {
		if(a[i].fi == a[i + 1].fi) {
			l = min(a[i].se , a[i + 1].se) + 1;
			r = max(a[i].se , a[i + 1].se);
			for(int j = l ; j <= r ; j++) 
				row[j].pb(a[i].fi);
		}
	}
	for(int i = 1 ; i <= h ; i++) {
	//	cout << row[i].size() << ' ';
		if(row[i].size()) {
			sort(row[i].begin() , row[i].end());
			for(int k = 0 ; k < row[i].size() - 1 ; k += 2) 
				for(int j = row[i][k] + 1 ; j <= row[i][k + 1] ; j++)
					ans[i][j] = 1;
		}
		//cout << '\n';
	}
	for(int i = h ; i >= 1 ; i--) {
		for(int j = 1 ; j <= w ; j++)
			cout << ((ans[i][j]) ? '#' : '.' );
		cout << '\n';
	}
}


