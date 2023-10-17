#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , M = 1e6 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , a[N] , d[N] , l[N] , f[N];

void sieve() {
	for(int i = 2 ; i <= sqrt(M) ; i++)
		if(!l[i]) for(int j = i * i ; j <= M ; j += i) if(!l[j]) l[j] = i;
	for(int i = 1 ; i <= M ; i++) 
		if(!l[i]) l[i] = i;
}

int calc(int x) {
	int t = 0;
	while(x != 1) {
		int y = l[x];
		x /= y;
		if(x % y == 0) return 0;
		t++;
	}
	return ((t % 2) ? 1 : -1);
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , d[a[i]] = 1;
	sieve();
	for(int i = 2 ; i <= M ; i++) f[i] = calc(i);
	for(int i = M ; i >= 1 ; i--) if(!d[i]) {
		ll m = M / i , count = 0 , c = 0;
		for(int j = 2 ; j <= m ; j++) {
			count += d[j * i];
			int dem = 0;
			for(int k = j ; k <= m ; k += j) dem += d[k * i];
			c += 1LL * f[j] * dem * (dem - 1) / 2;
		}
		count = count * (count - 1) / 2;
		if(c != count) d[i] = 1 , ans++;
	}
	cout << ans;
	return 0;
}

