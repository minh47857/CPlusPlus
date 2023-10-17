#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 2e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("ddb.inp" , "r" , stdin);
	freopen("ddb.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , p[N] , f[N];

int main() {
	file();
	cin >> t;
	p[1] = 1;
	for(int i = 2 ; i <= sqrt(2e6) ; i++)
		if(!p[i]) for(int j = i * i ; j <= 2e6 ; j += i) p[j] = 1;
	for(int i = 1 ; i <= 2e6 ; i++) f[i] = f[i - 1] + 1 - p[i];
	while(t--) {
		int n ; cin >> n;
		cout << f[2 * n] - f[n] << '\n';
	}
	return 0;
}

