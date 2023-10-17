#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t;

int main() {
	cin >> t;
	while(t--) {
		ll l , r , ans = 0 ; cin >> l >> r;
		for(int i = l ; i <= r ; i++) ans += ((i + 1) / 2);
		cout << ans << '\n';
	}
}

