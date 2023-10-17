#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("chiahet.inp" , "r" , stdin);
	freopen("chiahet.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll a , b , x , y;

int solve(int p) {
	return b / p - (a + p - 1) / p + 1;
}

int main() {
	file();
	cin >> a >> b >> x >> y;
	cout << solve(x) + solve(y) - solve(x * y / __gcd(x , y));
	return 0;
}

