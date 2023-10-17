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

ll rand(int l , int r) {
	return l + rng() % (r - l + 1);
}

int n , k , A1 , A2 , B1 , B2;

int main() {
	n = rand(1 , 100);
	k = rand(1 , 10000);
	A1 = rand(1 , n - 1) , B1 = rand(A1 + 1 , n);
	A2 = rand(1 , n - 1) , B2 = rand(A2 + 1 , n);
	cout << n << ' ' << k << '\n' << A1 << ' ' << B1 << '\n' << A2 << ' ' << B2;
}

