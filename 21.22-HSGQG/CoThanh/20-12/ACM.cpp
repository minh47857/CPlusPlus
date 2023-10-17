#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 3e4 + 5 , M = 1 << 12;

using namespace std;

void file() {
	freopen("ACM.in" , "r" , stdin);
	freopen("ACM.ans" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N][15];
ll f[M] , ans = 0 , sum[N];

void gen(int t , int mask) {
	for(int i = 0 , nmask ; i <= 1 ; i++) {
		nmask = mask | (i * (1 << t));
		for(int j = 1 ; j <= n ; j++) sum[j] += i * a[j][t + 1];
			if(t == 10)	for(int j = 1 ; j <= n ; j++) f[nmask] = max(f[nmask] , sum[j]);
			else gen(t + 1 , nmask);
		for(int j = 1 ; j <= n ; j++) sum[j] -= i * a[j][t + 1];
	}
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= 11 ; j++)
	  	cin >> a[i][j];
	gen(0 , 0);
	for(int mask1 = 0 ; mask1 < (1 << 11) ; mask1++)	
	  for(int mask2 = 0 ; mask2 < (1 << 11) ; mask2++) {
	  	if(mask1 & mask2) continue;
	  	ans = max(ans , f[mask1] + f[mask2] + f[((1 << 11) - 1) ^ mask1 ^ mask2]);
	  }
	cout << ans;
	return 0;
}


