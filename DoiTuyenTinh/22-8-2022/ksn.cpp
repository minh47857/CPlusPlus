#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 2e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("ksn.inp" , "r" , stdin);
	freopen("ksn.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k , a , b , ans , c[N] , d[N];

int main() {
	file();
	cin >> k >> a >> b;
	for(int i = a ; i <= b ; i++) d[i - a] = i;
	for(int i = 2 ; i <= sqrt(k) ; i++)
		if(!c[i]) for(int j = i * i ; j <= k ; j += i) c[j] = 1;
	for(int i = 2 ; i <= k ; i++) if(!c[i]) 
		for(int j = (a + i - 1) / i * i ; j <= b ; j += i) 
			while(d[j - a] % i == 0) d[j - a] /= i;
	for(int i = 0 ; i <= b - a ; i++) ans += (d[i] == 1);
	cout << ans;
	return 0;
}

