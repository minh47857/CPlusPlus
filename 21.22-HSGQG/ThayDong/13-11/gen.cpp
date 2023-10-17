#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
random_device dev;
mt19937 rng((unsigned int) chrono::steady_clock().now().time_since_epoch().count());
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n ;
int rand(int l , int r) {
	return rng() % (r - l + 1) + l;
}

int main() {
	n = rand(3 , 3);
	cout << rand(2 , 10) << ' ' << 1 << ' ' << n << '\n';
	for(int i = 1 ; i <= n ; i++) cout << rand(2 , 10000000) + i % 2<< ' ';
	return 0;
}

