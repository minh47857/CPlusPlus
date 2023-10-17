#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 100 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	freopen("fibo9.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int f[N];

int main() {
	file();
	f[1] = 1;
	for(int i = 2 ; i <= N ; i++) 
		f[i] = (f[i - 2] + f[i - 1]) % MOD , cout << i << ' ' << f[i] << '\n';
}

