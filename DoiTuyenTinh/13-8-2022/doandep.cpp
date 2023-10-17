#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , M = 1e6;
const ll inf = 1e18;

void file() {
	freopen("doandep.inp" , "r" , stdin);
	freopen("doandep.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , c[N] , a[N];
ll l = inf , s , ans = -inf;

void sieve() {
	for(int i = 2 ; i <= sqrt(M) ; i++)
		if(!c[i]) for(int j = i * i ; j <= M ; j += i) c[j] = 1;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sieve();
	for(int i = 1 ; i <= n ; i++) {
		s += a[i];
		if(!c[i]) ans = max(ans , s - l);
		if(!c[i + 1]) l = min(l , s);
	}
	cout << ans;
	return 0;
}

