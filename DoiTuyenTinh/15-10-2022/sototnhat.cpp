#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("sototnhat.inp" , "r" , stdin);
	freopen("sototnhat.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , res = 0;

int calc(int x) {
	int dem = 0;
	while(x) dem += x % 10 , x /= 10;
	return dem;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		if(n % i == 0) 
			if(calc(i) > calc(res)) res = i;
	cout << res;
	return 0;
}

