#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("pseprime.inp" , "r" , stdin);
	freopen("pseprime.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , p[N];

int Pow(int x , int y , int mod) {
	if(y == 0) return 1;
	ll res = Pow(x , y / 2 , mod);
	res = res * res % mod;
	if(y % 2) return res * x % mod;
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 2 ; i <= sqrt(n) ; i++)
		if(!p[i]) for(int j = i * i ; j <= n ; j += i) p[j] = 1;
	for(int i = 2 ; i <= n ; i++)
		if(p[i] && Pow(2 , i , i) == 2) cout << i << '\n';
	return 0; 
}

