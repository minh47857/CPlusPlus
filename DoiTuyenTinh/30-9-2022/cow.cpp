#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
#define Bit(x , k) ((x >> k) & 1)
using namespace std;

const int N = 1 << 25 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("cow.inp" , "r" , stdin);
	freopen("cow.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[25] , b[25] , f[N];

int main() {
	file();
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) cin >> b[i];
	f[0] = 1;
	for(int mask = 0 ; mask < (1 << n) ; mask++) {
		int t = __builtin_popcount(mask);
		for(int i = 0 ; i < n ; i++) if(!Bit(mask , i)) {
			if(a[i] <= b[t]) f[mask | (1 << i)] += f[mask];
		}
	}
	cout << f[(1 << n) - 1];
	return 0;
}

