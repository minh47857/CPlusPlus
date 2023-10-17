#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("PerGraph.inp" , "r" , stdin);
	freopen("PerGraph.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , p = 1 , s = 1;

int main() {
	file();
	cin >> n;
	for(int i = 2 ; i <= n ; i++) {
		p = (p * i) % MOD;
		s = (s * 2) % MOD;
	}
	cout << (p + MOD - s) % MOD;
	return 0;
}


