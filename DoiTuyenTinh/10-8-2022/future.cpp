#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e4 + 5 , M = 1e6 , inf = 1e9 + 7;

void file() {
	freopen("future.inp" , "r" , stdin);
	freopen("future.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , ans , c[M + 5];

void sieve() {
	c[0] = c[1] = 1;
	for(int i = 2 ; i <= sqrt(M) ; i++)
		if(!c[i]) for(int j = i * i ; j <= M ; j += i) c[j] = 1;
}

bool check(int x) {
	if(!c[x] || x == 1) return false;
	for(int i = 2 ; i <= sqrt(x) ; i++) 
		if(x % i == 0) 
			if(c[i] || c[x / i]) return false;
	return true;	
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sieve();
	for(int i = 1 ; i <= n ; i++) ans += check(a[i]);
	cout << ans;
	return 0;
}

