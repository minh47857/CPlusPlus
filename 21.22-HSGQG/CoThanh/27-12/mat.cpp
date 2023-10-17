#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 25 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("mat.inp" , "r" , stdin);
	freopen("mat.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct matrix {
	int v[N][N];
};

int n , k;
matrix res;

matrix combine(matrix a , matrix b) {
	matrix ans;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= n ; j++)
	  	ans.v[i][j] = 0;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= n ; j++)
	    for (int l = 1 ; l <= n ; l++) 
	    	ans.v[i][j] = (ans.v[i][j] + a.v[i][l] * b.v[l][j]) % 10;
	return ans;
}

matrix Pow(matrix a , int b) {
	if(b == 1) return a;
	matrix t = Pow(a , b / 2);
	t = combine(t , t);
	if(b % 2) return combine(a , t);
	return t;
}

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= n ; j++)
	  	cin >> res.v[i][j] , res.v[i][j] %= 10;
	res = Pow(res , k);
	for(int i = 1 ; i <= n ; i++) {
	  for(int j = 1 ; j <= n ; j++)
	  	cout << res.v[i][j] << ' ';
	  cout << '\n';
	}
	return 0;
}


