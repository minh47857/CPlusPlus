#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 85 , MOD = 1e9 + 9 , inf = 1e9 + 7,
		  col[] = {2 , 2 , 1 , 1 , -1 , -1 , -2 , -2},
		  row[] = {1 , -1 , 2 , -2 , 2 , -2 , 1 , -1};
	      

using namespace std;

void file() {
	freopen("knights.inp" , "r" , stdin);
	freopen("knights.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct matrix {
	ll v[N][N];
};

matrix ans , c;
int n , m , k , f[N];

matrix mul(matrix a , matrix b) {
	matrix res;
	for(int i = 1 ; i <= k ; i++)
		for(int j = 1 ; j <= k ; j++)
			res.v[i][j] = 0;
	for(int i = 1 ; i <= k ; i++)
		for(int j = 1 ; j <= k ; j++)
			for(int l = 1 ; l <= k ; l++)
				res.v[i][j] = (res.v[i][j] + a.v[i][l] * b.v[l][j] % MOD) % MOD;
	return res;
}

matrix Pow(matrix a , int x) {
	if(x == 1) return a;
	matrix res = Pow(a , x / 2);
	res = mul(res , res);
	if(x % 2) return mul(res , a);
	return res;
}

int Bit(int x , int k) {
	return (x >> k) & 1;
}

int id(int i , int j) {
	return (j - 1) * m + i - 1;
}

bool check1(int mask) {
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= 2 ; j++) {
			if(!Bit(mask , id(i , j))) continue;
			for(int l = 0 ; l < 8 ; l++) {
				int u = i + row[l] , v = j + col[l];
				if(u < 1 || v < 1 || u > m || v > 2) continue;
				if(Bit(mask , id(u , v))) return false;
			}
		}
	return true;
}

bool check2(int x , int y) {
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= 2 ; j++) {
			if(!Bit(y , id(i , j))) continue;
			for(int l = 0 ; l < 8 ; l++) {
				int u = i + row[l] , v = j + col[l];
				if(v >= 1) continue;
				v += 2;
				if(u < 1 || v < 1 || u > m || v > 2) continue;
				if(Bit(x , id(u , v))) return false;
			}
		}
	return true;
}

int main() {
	file();
	cin >> m >> n;
	for(int i = 0 ; i < (1 << (2 * m)) ; i++) 
		if(check1(i)) f[++k] = i;
	for(int i = 1 ; i <= k ; i++)
		for(int j = 1 ; j <= k ; j++) 
			if(check2(f[i] , f[j])) c.v[i][j] = 1;
			else c.v[i][j] = 0;
	if(n % 2) {
		n++;
		for(int i = 1 ; i <= k ; i++) {
			bool ok = true;
			for(int j = 1 ; j <= m ; j++) 
				if(Bit(f[i] , id(j , 1))) ok = false;
			if(ok) ans.v[1][i] = 1;
			else ans.v[1][i] = 0;
		}
	}
	else for(int i = 1 ; i <= k ; i++) ans.v[1][i] = 1;
	if(n != 2) {
		c = Pow(c , (n - 2) / 2);
		ans = mul(ans , c);
	}
	ll res = 0;
	for(int i = 1 ; i <= k ; i++) 
		res = (res + ans.v[1][i]) % MOD;
	cout << res;
	return 0;
}


