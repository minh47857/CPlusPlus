#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , inf = 1e9;

void file() {
    freopen("FIBO.inp" , "r" , stdin);
	freopen("FIBO.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct matrix {
	ll v[4][4];
};

ll n , a , b , c , MOD;
matrix mod0 , mod1 , mod2 , P , ans;

matrix mul(matrix a , matrix b) {
	matrix res;
	for(int i = 1 ; i <= 3 ; i++) {
		for(int j = 1 ; j <= 3 ; j++) {
			res.v[i][j] = 0;
			for(int k = 1 ; k <= 3 ; k++) 
			res.v[i][j] = (res.v[i][j] + a.v[i][k] * b.v[k][j]) % MOD;
		}
	}
	return res;
}

matrix Pow(matrix a , ll b) {
	if(b == 0) {
		matrix res;
		for(int i = 1 ; i <= 3 ; i++)
		for(int j = 1 ; j <= 3 ; j++)
		res.v[i][j] = 1;
		return res;
	}
	if(b == 1) return a;
	matrix res = Pow(a , b / 2);
	res = mul(res , res);
	if(b % 2) return mul(a , res);
	return  res;
}

void solve() {
	if(n <= 3) {
		cout << n % MOD << '\n';
		return;
	}
	for(int i = 1 ; i <= 3 ; i++)
	for(int j = 1 ; j <= 3 ; j++)
		ans.v[i][j] = mod0.v[i][j] = mod1.v[i][j] = mod2.v[i][j] = 0;
	mod1.v[1][1] = mod2.v[3][1] = mod0.v[2][1] = a;
	mod1.v[2][1] = mod2.v[1][1] = mod0.v[3][1] = b;
	mod1.v[3][1] = mod2.v[2][1] = mod0.v[1][1] = c;
	mod1.v[1][2] = mod2.v[1][2] = mod0.v[1][2] = 1;
	mod1.v[2][3] = mod2.v[2][3] = mod0.v[2][3] = 1;
	ans.v[1][1] = 3 , ans.v[1][2] = 2 , ans.v[1][3] = 1;
    P = mul(mod1 , mod2);
    P = mul(P , mod0);
    P = Pow(P , (n - 3) / 3);
    if((n - 3) % 3 == 1 || (n - 3) % 3 == 2) {
    	if((n - 3) / 3 == 0) P = mod1;
    	else P = mul(P , mod1);
    }
    if((n - 3) % 3 == 2) P = mul(P , mod2);
    ans = mul(ans , P);
    cout << ans.v[1][1] << '\n';
}
 
int main() {
	file();
	while(cin >> a >> b >> c >> MOD >> n) solve();
	return 0;
} 
 


