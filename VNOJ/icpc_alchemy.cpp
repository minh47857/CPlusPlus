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

int t , m;

int main() {
	cin >> t;
	while(t--) {
		cin >> m;
		int ans = 0;
		for(int i = 1 ; i <= m ; i++) ans ^= i;
		cout << m - (ans != m) << '\n';
		for(int i = 1 ; i <= m ; i++) if(i != (ans ^ m)) cout << i << ' ';
		cout << '\n';
    }
}
