#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	int n , m , t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		if(n > m) swap(n , m);
	//	cout << n << ' ' << m << '\n';
		if(n * m == 1) cout << 0 << '\n';
	    else if(n == 1) cout << 1 << '\n';
	    else cout << 2 << '\n';
	}
}

