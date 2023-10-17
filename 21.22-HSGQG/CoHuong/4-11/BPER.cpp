#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("BPER.inp" , "r" , stdin);
	freopen("BPER.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;

namespace sub2 {
	int res = 0 , dp[1 << 21][60];
	int Bit(int x , int k) {
		return (x >> k) & 1;
	}
	
	void add(int&a , int b) {
		a += b;
		if(a >= MOD) a -= MOD;
	}
	
	void solve() {
		res = 0;
		dp[0][0] = 1;
		for(int i = 1 ; i <= n ; i++) res += (i % 10 + (i / 10) % 10);
		for(int mask = 0 ; mask < (1 << n) ; mask++) {
			int k = 0;
			for(int i = 0 ; i < n ; i++) if(Bit(mask , i)) {
				if(i + 1 >= 10) k += 2;
				else k++;
			}
			for(int s = 0 ; s <= 51 ; s++) {
				if(dp[mask][s] == 0 || 2 * s > res) continue;
				for(int i = 0 ; i < n ; i++) if(!Bit(mask , i)) { 
				int nmask = mask | (1 << i) , val = s;
				if(i + 1 >= 10) {
					if(k % 2 == 0) val = val + (((i + 1) / 10) % 10);
					else val = val + ((i + 1) % 10);
				}
				else if(k % 2 == 0) val = val + ((i + 1) % 10);
                add(dp[nmask][val] , dp[mask][s]);
				}
			}
		}
		if(res % 2) cout << 0;
		else cout << dp[(1 << n) - 1][res / 2];
		cout << endl;
	}
}

int main() {
//	file();
	cin >> n;
	if(n <= 20) sub2::solve();
	return 0;
}

