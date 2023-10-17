#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("caro.inp" , "r" , stdin);
	freopen("caro.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string a[3];
int d[3][3] , ok[30] , res1 , res2;

bool check() {
	bool ok = false;
	for(int i = 0 ; i <= 2 ; i++) {
		ok |= (d[i][0] && d[i][1] && d[i][2]);
		ok |= (d[0][i] && d[1][i] && d[2][i]);
	}
	ok |= (d[0][0] && d[1][1] && d[2][2]);
	ok |= (d[0][2] && d[1][1] && d[2][0]);
	return ok;
}

int main() {
	file();
	cin >> a[0] >> a[1] >> a[2];
	for(int i = 0 ; i <= 2 ; i++)
		for(int j = 0 ; j <= 2 ; j++)
			ok[a[i][j] - 'A'] = 1;
	for(char x = 'A' ; x <= 'Z' ; x++) {
		for(int i = 0 ; i <= 2 ; i++)
			for(int j = 0 ; j <= 2 ; j++)
				d[i][j] = (a[i][j] == x);
		res1 += check();
	}
	for(char x = 'A' ; x <= 'Z' ; x++) 
		for(char y = x + 1 ; y <= 'Z' ; y++) {
			if(!ok[x - 'A'] || !ok[y - 'A']) continue;
			for(int i = 0 ; i <= 2 ; i++)
				for(int j = 0 ; j <= 2 ; j++)
					d[i][j] = (a[i][j] == x || a[i][j] == y);
			res2 += check();
		}
	cout << res1 << '\n' << res2;
	return 0;
}

