#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e3 + 5 , P = 55;

using namespace std;

int n , m , p , a[N][N];

namespace sub1 {
	int f[N][P] , ans[N];
	pi trace[N][P];
	
	void solve() {
		memset(f , 0x3f , sizeof(f));
		f[0][0] = 0;
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < p ; j++) {
				for(int num = 0 , w ; num <= 9 ; num++) {
					if(a[1][i + 1] > num) w = min(a[1][i + 1] - num , 10 + num - a[1][i + 1]);
					else w = min(num - a[1][i + 1] , 10 + a[1][i + 1] - num);
					if(f[i + 1][(j * 10 + num) % p] > f[i][j] + w) {
						trace[i + 1][(j * 10 + num) % p] = {j , num};
						f[i + 1][(j * 10 + num) % p] = min(f[i + 1][(j * 10 + num) % p] , f[i][j] + w);
					}
				}
			}
		}
		cout << f[n][0] << '\n';
		int j = 0;
		for(int i = n ; i >= 1 ; i--) {
			ans[i] = trace[i][j].se;
			j = trace[i][j].fi;
		}
		for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
	}
}

namespace sub23 {
	int f[N][N][P];
	void solve() {
		memset(f , 0x3f , sizeof(f));
		f[0][1][0] = 0;
		for(int i = 1 ; i <= m ; i++) {
			for(int j = 1 ; j <= n ; j++) {
				for(int l = 0 ; l < p ; l++) {
					for(int num = 0 , w , w1 , w2 , l1 , l2 ; num <= 9 ; num++) {
						if(a[i][j - 1] > num) w1 = min(a[i][j - 1] - num , 10 + num - a[i][j - 1]);
							else w1 = min(num - a[i][j - 1] , 10 + a[i][j - 1] - num);	
						if(a[i - 1][j] > num) w2 = min(a[i - 1][j] - num , 10 + num - a[i - 1][j]);
							else w2 = min(num - a[i - 1][j] , 10 + a[i - 1][j] - num);
						l1 = l2 = (j - num + j) % p;
						w = 0;
						if(i - 1 != 0)	w = f[i - 1][j][l2] + w2;
						if(j - 1 != 0)  w += f[i][j - 1][l1] + w1;
						f[i][j][l] = min(f[i][j][l] , w);
					}
				}
			}
		}
		cout << f[m][n][0];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> m >> n >> p;
	for(int i = 1 ; i <= m ; i++) 
		for(int j = 1 ; j <= n ; j++) 
			cin >> a[i][j];
	if(m == 1) sub1::solve();
	else sub23::solve();
}

