#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 6e4 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("EX.inp" , "r" , stdin);
	freopen("EX.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll f[20][N][2][2] , Pow[15] , l , r;
int a[20];

int Bit(int x , int k) {
	return (x / Pow[k]) % 3;
}

int convert(int x , int k) {
	return x + Pow[k];
}

ll calc(int id , int tt , int ok , int ok2) {
	if(f[id][tt][ok][ok2] != -1) return f[id][tt][ok][ok2];
	if(id == 0) return ok2;
	ll res = 0;
	for(int i = 0 ; i <= max(a[id] , ok * 9) ; i++) {
		if(Bit(tt , i) == 2) continue;
		if(!ok2 && i == 0) 
			res += calc(id - 1 , tt , ok | (i != a[id]) , ok2);
		else 
			res += calc(id - 1 , convert(tt , i) , ok | (i != a[id]) , ok2 | (i != 0));
	}
	f[id][tt][ok][ok2] = res;
	return res;
}

ll solve(ll x) {
	for(int i = 1 ; i <= 19 ; i++ , x /= 10) 
		a[i] = x % 10 ;
	memset(f , -1 , sizeof(f));
	return calc(19 , 0 , 0 , 0);
}

int main() {
	file();
	Pow[0] = 1;
	for(int i = 1 ; i <= 10 ; i++) 
		Pow[i] = Pow[i - 1] * 3;
	cin >> l >> r;
	cout << solve(r) - solve(l - 1);
	return 0;
}



