#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("uss.inp" , "r" , stdin);
	freopen("uss.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k[N];

namespace sub2 {
	void solve() {
	   cout << k[1] * k[2] - 1 << '\n';
	   for(int i = 0 ; i < k[1] ; i++) {
	    if(i % 2 == 0) for(int j = 0 ; j < k[2] ; j++) {
	    	if(i == 0 && j == 0) continue;
	    	cout << i << ' ' << j << '\n';
	    }
	    else for(int j = k[2] - 1 ; j >= 0 ; j--) cout << i << ' ' << j << '\n';
	   }
	}
}

int main() {
 file();
 cin >> n;
 for(int i = 1 ; i <= n ; i++) cin >> k[i];
 if(n == 2) sub2::solve();
}

