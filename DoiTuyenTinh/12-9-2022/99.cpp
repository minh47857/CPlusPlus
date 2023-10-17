#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("99.inp" , "r" , stdin);
	freopen("99.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;

int main() {
	file();
	cin >> n;
	if(n % 9) cout << n % 9;
	while(n >= 9) cout << 9 , n -= 9;
	return 0;
}

