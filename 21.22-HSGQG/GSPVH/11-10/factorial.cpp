#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 1e7 + 5 , M = 1e6 + 5 , inf = 1e13;

void file() {
    freopen("factorial.inp" , "r" , stdin);
	freopen("factorial.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[M] , Prime[M] , id[N] , Isprime[N] , l[N] , cnt;
ll Pow[M];

ll Get(ll x , int y) {
	ll p = y , res = 0;
	while(p <= x) {
		res += x / p;
		p *= y;
	}
	return res;
}

void sieve() {
	Isprime[0] = Isprime[1] = 1;
	for(int i = 2 ; i <= sqrt(a[n]) ; i++) {
		if(!Isprime[i]) 
		    for(int j = i * i ; j <= a[n] ; j += i) Isprime[j] = 1 , l[j] = i;
	}
	for(int i = 2 ; i <= a[n] ; i++) 
	   if(!Isprime[i]) Prime[++cnt] = i , l[i] = i , id[i] = cnt;
}

bool check(ll x) {
	for(int i = 1 ; i <= cnt ; i++) if(Get(x , Prime[i]) < Pow[i]) return false;
	return true;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	sieve();
	for(int i = 1 ; i <= n ; i++)
	   for(int j = a[i - 1] + 1 ; j <= a[i] ; j++) {
	   	int x = j;
		   	while(x != 1) {
		    int y = l[x];
			while(x % y == 0) x /= y , Pow[id[y]] += (n - i + 1);
	       }
	   }
	ll d = 0 , c = inf , g , ans;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g))  ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}


