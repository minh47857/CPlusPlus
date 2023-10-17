#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("swap.inp" , "r" , stdin);
	freopen("swap.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k , A1 , B1 , A2 , B2 , a[N] , ans[N] , nx[N];
pi f[N];
vector<int> s[N];

int main() {
	file();
	cin >> n >> k >> A1 >> B1 >> A2 >> B2;
	for(int i = 1 ; i <= n ; i++) a[i] = i;
	for(int i = A1 ; i <= B1 - (B1 - A1 + 1) / 2; i++) swap(a[i] , a[B1 - i + A1]);
	for(int i = A2 ; i <= B2 - (B2 - A2 + 1) / 2 ; i++) swap(a[i] , a[B2 - i + A2]);
	for(int i = 1 ; i <= n ; i++) nx[a[i]] = i;
	for(int i = 1 ; i <= n ; i++) if(!f[i].se) {
		int x = i;
		s[++m].pb(x);
		f[x] = {s[m].size() - 1 , m};
		x = nx[x];
		while(x != i) {
			s[m].pb(x);
			f[x] = {s[m].size() - 1 , m};
			x = nx[x];
		}
	}
	for(int i = 1 ; i <= n ; i++) {
		int q = f[i].se , p = f[i].fi;
		ans[s[q][(p + k) % s[q].size()]] = i;
	}
	for(int i = 1 ; i <= n ; i++) cout << ans[i] << '\n';
	return 0;
}

