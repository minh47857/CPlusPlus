#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
	int a[N] , f[N] , k , n , ans , g[N];

int Bit(int x , int k) {
	return (x >> k) & 1;
}

int calc(int mask) {
	if(f[mask] != -1) return f[mask];
	if(mask == 0) return 1;
	int res = 0;
	for(int i = 0 ; i < n ; i++) if(Bit(mask , i)) {
		for(int j = i + 1 ; j < n ; j++) if(Bit(mask , j) && (a[j] - a[i] == k)) res += calc(mask ^ (1 << i) ^ (1 << j));
	}
	//cout << mask << ' ' << res << endl;
	f[mask] = res;
	return res;
}

int main() {
	cin >> n >> k;
		for(int i = 0 ; i < n ; i++) cin >> a[i]; 
		g[0]=  1;
		for(int i = 1 ; i <= n ; i++) g[i] = g[i - 1] * i;
		sort(a , a + n);
		memset(f , -1 , sizeof(f));
		ans = calc((1 << n) - 1);
		cout << ans / g[n / 2];
}


