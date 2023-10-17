#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("biendoi.inp" , "r" , stdin);
	freopen("biendoi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int x , d1 , d2;

int main() {
	file();
	cin >> x;
	while(x % 2 == 0) x /= 2 , d1++;
	while(x % 3 == 0) x /= 3 , d2++;
	if(x != 1 || d2 > d1) {
		cout << -1;
		return 0;
	}
	cout << 2 * d1 - d2;
	return 0;
}

