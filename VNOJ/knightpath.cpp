#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 70 , MOD = 4294967296,
	row[] = {1 , -2 , 2 , -1 , -2 , 2 , -2 , 1}, 
	col[] = {2 , 1 , -1 , 2 , -1 , -1 , 1 , -2};

void file()
{
    freopen("knightpath.inp" , "r" , stdin);
    freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n , k , sum = 0;

struct Matrix {
    ll v[N][N];
};

Matrix combine(Matrix a , Matrix b) {
    Matrix res;
    for (int i = 1 ; i <= n ; i++)
     for (int j  = 1 ; j <= n ; j++)
      res.v[i][j] = 0;
    for (int i = 1 ; i <= n ; i++)
     for (int j = 1 ; j <= n ; j++)
     for (int l = 1 ; l <= n ; l++)
       res.v[i][j] = (res.v[i][j] + a.v[i][l] * b.v[l][j]) % MOD;
   return res;
}

Matrix Pow(Matrix a , ll b) {	
	if(b == 1) return a;
	Matrix t = Pow(a, b / 2);
	if(b % 2){
		return combine(combine(t, t), a);
	}
	return combine(t, t);
}

int id(int i , int j) {
	return (i - 1) * 8 + j;
}

int main() {
	file();
	cin >> k;
	n = 64;
	if(k == 0) {
		cout << 1;
		return 0;
	}
	Matrix c , ans;
	for(int i = 1 ; i <= 8 ; i++)
	 for(int j = 1 ; j <= 8 ; j++)
	 	c.v[i][j] = ans.v[i][j] = 0;
	ans.v[1][1] = 1;
	for(int i = 1 ; i <= 8 ; i++)
	 for(int j = 1 ; j <= 8 ; j++)
	  for(int x = 0 ; x < 8 ; x++) {
	  	int u = i + row[x] , v = j + col[x];
	  	if(u >= 1 && u <= 8 && v >= 1 && v <= 8)
		  	cout << i << ' ' << j << "||" << ' ' << u << ' ' << v << '\n' , c.v[id(i , j)][id(u , v)] = 1;
	  }
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			cout << c.v[i][j] << ' ';
		}
		cout << endl;
	}
	c = Pow(c , k);
	ans = combine(ans , c);
	for(int i = 1 ; i <= n ; i++)
		sum = (sum + ans.v[1][i]) % MOD;
	cout << sum;	
	return 0;
}
