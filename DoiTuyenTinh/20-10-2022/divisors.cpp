#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9,
		  prime[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19};

void file() {
	freopen("divisors.inp" , "r" , stdin);
	freopen("divisors.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , d[10];
ll ans = 1;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		for(int x = 0 , p = i; x <= 7 ; x++)
			while(p % prime[x] == 0) d[x]++ , p /= prime[x];
	for(int i = 0 ; i <= 7 ; i++) ans *= (d[i] + 1);
	cout << ans - 1;
	return 0;
}

