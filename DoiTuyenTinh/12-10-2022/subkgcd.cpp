#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , M = 1e6 , inf = 1e9;

void file() {
	freopen("subkgcd.inp" , "r" , stdin);
	freopen("subkgcd.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , ans = 1 , dem , d[N] , f[N];

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 , x ; i <= n ; i++) cin >> x , d[x]++;
	for(int i = 1 ; i <= M ; i++) f[i] = f[i - 1] + d[i];
	for(int i = 2 ; i <= M ; i++) {
		int tmp = 0;
		for(int j = 0 ; j <= M ; j += i) 
			tmp += f[min({j + k , j + i - 1 , M})] - f[j - 1];
		if(tmp == n) ans = i;
	}
	cout << ans;
	return 0;
} 

