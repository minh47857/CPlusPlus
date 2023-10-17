#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 3e5 + 5 , MOD = 1e9 + 7;

void file() {
	freopen("CUTSTR.inp" , "r" , stdin);
	freopen("CUTSTR.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s , t;
int n , m;
ll Pow[N] , Hash[N] , HashT , f[N] , base = 31;

ll Get(int x , int y) {
	return (Hash[y] - Hash[x - 1] * Pow[y - x + 1] + MOD * MOD) % MOD;
}

int main() {
	file();
   cin >> s >> t;
   n = s.size() , m = t.size();
   s = ' ' + s;
   t = ' ' + t;
   Pow[0] = 1;
   for(int i = 1 ; i <= n ; i++) Pow[i] = (Pow[i - 1] * base) % MOD;
   for(int i = 1 ; i <= n ; i++) Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % MOD;
   for(int i = 1 ; i <= m ; i++) HashT = (HashT * base + t[i] - 'a' + 1) % MOD;
   f[0] = 1;
   for(int i = 1 ; i <= n - m + 1 ; i++) {
   	ll res;
   	 if(Get(i , i + m - 1) == HashT) {
   	 	if(i <= m) res = 1;
   	 	else res = f[i - m];
	  }
   	 else res = 0;
   	 f[i] = (f[i - 1] + res) % MOD;
   }
   cout << f[n - m + 1] - 1;
   return 0;
}


