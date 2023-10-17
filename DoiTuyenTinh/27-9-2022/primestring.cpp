#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("primestring.inp" , "r" , stdin);
	freopen("primestring.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int q , res , d[35] , f[35];
string s;

int main() {
	file();
	cin >> q;
	f[2] = 1 , f[3] = 1 , f[5] = 1 , f[7] = 1;
	f[11] = 1 , f[13] = 1 , f[17] = 1 , f[23] = 1;
	while(q--) {
		cin >> s;
		memset(d , 0 , sizeof(d));
		res = 0;
		for(auto i : s) d[i - 'a']++;
		for(int i = 0 ; i <= 25 ; i++) res += (d[i] == 1);
		cout << (f[res] ? "YES\n" : "NO\n");
	}
	return 0;
}

