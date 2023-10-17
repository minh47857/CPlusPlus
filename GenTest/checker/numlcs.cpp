#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , MOD = 20030101 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , m , l[N];
pi pre[N][N] , f[N][N];
string a , b;

pi get(pi x , pi y) {
	if(x.fi != y.fi) return max(x , y);
	else return {x.fi , (x.se + y.se) % MOD};
}

void solve() {
	cin >> a >> b;
	n = a.size() , m = b.size();
	a = ' ' + a;
	b = ' ' + b;
	memset(l , 0 , sizeof(l));
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			pre[i][j] = {0 , 1};
	for(int i = 0 ; i <= max(m , n) ; i++) f[i][0] = f[0][i] =  {0 , 1};
	for(int i = 1 ; i <= n ; i++) {
		int last = 0;
		for(int j = 1 ; j <= m ; j++) {
			if(a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1];
				f[i][j].fi++;
				pre[i][j] = f[i][j];
				last = j;
			}
			else {
				pre[i][j] = pre[i - 1][j];
				if(l[last] && f[l[last]][last].fi == pre[i][j].fi) 
					pre[i][j].se = (pre[i][j].se - f[l[last]][last].se + MOD) % MOD;
				if(last) pre[i][j] = get(pre[i][j] , f[i][last]);
				f[i][j] = pre[i][j];
		}
		for(int j = 1 ; j <= m ; j++) 
			if(a[i] == b[j]) l[j] = i;
	}
	if(f[n][m].fi == 0) f[n][m].se = 0;
	cout << f[n][m].fi << ' ' << f[n][m].se << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}
