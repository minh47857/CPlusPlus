
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
 
const int N = 405 , M = 5e5 + 5 , inf = 1e9;
 
void file() {
	freopen("DaiLy.inp" ,"r" , stdin);
	freopen("DaiLy.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}
 
int n , m;
 
namespace sub3 {
	int x[N] , dp[N][N][N];
	ll ans = 0;
	void Dp() {
		for(int i = 1 ; i <= n ; i++)
			for(int j = i + 1 ; j <= n ; j++)
				dp[i][j][0] = x[j] - x[i];
		for (int i = 1; i <= n; i++) {
			for (int r = 1; r <= n; r++) {
				for (int j = i + 1, k = i; j <= n; j++) {
					while (k < j && dp[i][k][r - 1] < x[j] - x[k]) k++;
					dp[i][j][r] = min(dp[i][k][r - 1], x[j] - x[k - 1]);
				}
			}
		}
	}
	void solve() {
		for(int i = 1 ; i <= n ; i++) 
			cin >> x[i];
		Dp();
		for(int i = 1 ; i <= m ; i++) {
			int s , f , r , c;
			cin >> s >> f >> c >> r;
			ans = max(ans , 1LL * dp[s][f][r] * c);
		}
			
		cout << ans;
	}
}
 
namespace sub1 {
	int x[100005] , s , f , C , r;
	bool check(int K) {
		int dem = 0 , sum = 0;
		for(int i = s + 1; i <= f ; i++) {
			int val = x[i] - x[i - 1];
			if(val > K) return false;
			if(val + sum > K) {
				if(dem < r) sum = val , dem++;
				else return false;
			}
			else sum += val;
		}
		return true;
	}
	void solve() {
		for(int i = 1 ; i <= n ; i++) cin >> x[i]; 
		cin >> s >> f >> C >> r;
		int d = 1 , c = inf , g , ans;
		while(d <= c) {
			g = (d + c) / 2;
			if(check(g)) c = g - 1 , ans = g;
			else d = g + 1;
		}
		cout << 1LL * ans * C;
	}
}
 
int main() {
	file();
	cin >> n >> m;
	if(n <= 400) sub3::solve();
    else sub1::solve();
	return 0;
}
