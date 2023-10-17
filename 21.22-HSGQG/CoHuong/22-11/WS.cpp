#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5;

void file() {
	freopen("WS.inp" , "r" , stdin);
	freopen("WS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , MOD , ip[N] , g[N] , d[35] , num[N] , res = 1 , l[N];
vector<pi> f[N];
string str;

void Get(int m) {
	int x = m;
	while(x != 1) {
		int p1 , dem = 0;
		p1 = l[x];
		while((x % p1) == 0) x /= p1 , dem++;
		f[m].pb({p1 , dem});
	}
}

void Sieve() {
	ip[1] = 1;
	for(int i = 2 ; i <= sqrt(n) ; i++) 
		if(!ip[i]) for(int j = i * i ; j <= n ; j += i) if(!ip[j]) ip[j] = 1 , l[j] = i;
	for(int i = 1 ; i <= n ; i++) {
		if(!l[i]) l[i] = i;
		Get(i);
	}
}

int main() {
	file();
	cin >> MOD >> str;
	n = str.size();
	for(int i = 0 ; i < str.size() ; i++) d[str[i] - 'a' + 1]++;
	Sieve();
	for(int i = 1 ; i <= 30 ; i++) 
	 for(int j = 2 ; j <= d[i] ; j++) g[j]++;
	for(int i = 2 ; i <= n ; i++) 
	 for(auto x : f[i]) num[x.fi] += (x.se - g[i] * x.se);
	for(int i = 2 ; i <= n ; i++) {
		for(int j = 1 ; j <= num[i] ; j++) res = (res * i) % MOD;
	}
	cout << res;
	return 0;
}

