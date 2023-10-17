#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("gamed.inp" , "r" , stdin);
	freopen("gamed.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

ll n , l , r , nxl , nxr , a[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	if(a[n] == a[n - 1] + 1) {
		cout << 0;
		return 0;
	}
	l = a[n - 1] + 1 , r = a[n] - 1;
	a[0] = -2e9;
	for(int i = n - 1 ; i >= 1 ; i--) {
		nxr = a[i] - (l - a[i]);
		nxl = a[i] - (r - a[i]);
		l = max(nxl , a[i - 1] + 1);
		r = nxr;
		if(l >= a[i] || r <= a[i - 1]) {
			cout << 0;
			return 0;
		}
	}
	cout << r - l + 1;
	return 0;
}

