#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int main() {
	ll m , n;
	cin >> n >> m;
	if(n % 2) {
		cout << "IMPOSSIBLE";
	}
	else {
		ll a = m - n , b = 2 * n - m;
		if(a < 0 || b < 0 || a % 2 || b % 2) {
			cout << "IMPOSSIBLE";
		}
		else cout << a/2 << ' ' << b/2;
	}
}

