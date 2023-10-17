#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("bive.inp" , "r" , stdin);
	freopen("bive.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n;

int main() {
	file();
	cin >> t;
	while(t--) {
		cin >> n;
		if(n == 1) cout << 1 << '\n';
		else if(n == 0 || n == 2 || n == 4) cout << 0 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}

