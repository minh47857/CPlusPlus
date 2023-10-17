#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
pi f[N];

int main() {
	while(cin >> n) {	
		for(int i = 2 ; i <= n ; i++) 
			f[i].fi = (f[i - 1].fi + f[i - 1].se + 1 - i % 2) % MOD,
			f[i].se = (f[i - 1].fi + f[i - 1].se) % MOD;
		cout << f[n].fi << '\n';
	}
	return 0;
}

