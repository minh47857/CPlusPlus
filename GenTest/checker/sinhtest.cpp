#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>

using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll range(ll l , ll r) {
	return l + rng() % (r - l + 1);
}

int main() {
	cout << 1 << '\n';
	int n = range(1 , 10);
	int m = range(1 , 10);
	for(int i = 1 ; i <= n ; i++) cout << char('a' + range(0 , 25));
	cout << '\n';
	for(int i = 1 ; i <= m ; i++) cout << char('a' + range(0 , 25));
	return 0;
}

