#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("ghh.inp" , "r" , stdin);
	freopen("ghh.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n;

bool check (int x) {
	ll res = 0;
	for(int i = 1 ; i <= sqrt(x) ; i++) {
		if(x % i == 0) res += i;
		if(x % i == 0 && x / i != i) res += x / i;
	}
	return 2 * x <= res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) {
		cin >> x;
		cout << check(x) << '\n';
	}
	return 0;
}

