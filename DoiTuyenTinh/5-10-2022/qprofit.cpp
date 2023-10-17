#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("qprofit.inp" , "r" , stdin);
	freopen("qprofit.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int q , n , a[N] , p[N] , f[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	p[1] = 1;
	for(int i = 2 ; i <= sqrt(n) ; i++)
		if(!p[i]) for(int j = i * i ; j <= n ; j += i) p[j] = 1;
	for(int i = 1 ; i <= n ; i++)
		f[i] = f[i - 1] + a[i] - ((!p[i] && a[i] > 0) ? a[i] : 0);
	cin >> q;
	while(q--) {
		int l , r;
		cin >> l >> r;
		cout << f[r] - f[l - 1] << '\n';
	}
	return 0;
}

