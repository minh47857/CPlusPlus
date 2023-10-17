#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 2000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m = 0 , prime[N] , a[N] , t;

void sieve() {
	for(int i = 2 ; i < sqrt(N) ; i++) {
		if(prime[i] == 0) for(int j = i * i ; j < N ; j += i) prime[j] = 1;
	}
	ll pre = 2;
	for(ll i = 3 ; i < N ; i++) 	if(prime[i] == 0) a[++m] = i * pre , pre = i ;
	//for(int i = 1 ; i <= m ; i++) cout << a[i] << endl;
}

ll binary(int x) {
	ll d = 1 , c = m , g , kq = 0;
	while(d <= c) {
		g = (d + c) / 2;
		if(a[g] <= x) kq = a[g] , d = g + 1;
		else c = g - 1;
	}
	return kq;
}
int main() {
   sieve();
   cin >> t; 
   while(t--) {
   	cin >> n;
   	cout << n - binary(n) << '\n';
   }
   return 0;
}

