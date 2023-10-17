#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const ll N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("PURE.inp" , "r" , stdin);
	freopen("PURE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int m , n , base = 31;
ll Hash[N] , Pow[N];
string str;

ll get(int x , int y) {
	return (Hash[y] - Hash[x - 1] * Pow[y - x + 1] % MOD + MOD * MOD) % MOD;
}

bool check(int x) {
	for(int i = x + 1 ; i <= n - x + 1; i += x) 
		if(get(1 , x) != get(i , i + x - 1)) return false;
	if(n % x) 
		if(get(1 , n % x) != get(n - n % x + 1 , n)) return false;
	return true;
}

int main() {
	file();
	cin >> m >> str;
	n = str.size();
	m = min(m , n);
	str = ' ' + str;
	Pow[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		Pow[i] = Pow[i - 1] * base % MOD;
	for(int i = 1 ; i <= n ; i++) 
		Hash[i] = (Hash[i - 1] * base + str[i] - 'a' + 1) % MOD;
	for(int i = 1 ; i <= m ; i++) {
		if(check(i)) {
			for(int j = 1 ; j <= i ; j++) cout << str[j];
			return 0;
		}
	}
	cout << "NO";
	return 0;
}


