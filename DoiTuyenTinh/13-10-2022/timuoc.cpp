#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e4 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("timuoc.inp" , "r" , stdin);
	freopen("timuoc.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N];

bool check(int x) {
	for(int i = x + 1 ; i <= n ; i++) {
		if(a[i] != a[i - x]) return false;
	}
	return true;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) 
		if(n % i == 0) 
			if(check(i)) {
				cout << i;
				return 0;
			}
}

