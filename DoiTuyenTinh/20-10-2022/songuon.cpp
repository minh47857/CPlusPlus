#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("songuon.inp" , "r" , stdin);
	freopen("songuon.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n;

int calc(int x) {
	int res = 0;
	while(x) res += x % 10 , x /= 10;
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = max(0 , n - 100) ; i <= n ; i++) 
		if(i + calc(i) == n) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}

