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
	freopen("total.inp" , "r" , stdin);
	freopen("total.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , ans;

int main() {
	file();
	cin >> n;
	n *= 2;
	for(ll i = 1 ; i <= sqrt(n) ; i++) 
		if(n % i == 0) {
			ll tmp = n / i;
			if(abs(i - tmp) % 2 != 0) {
				ans++;
			}
			
		}
	cout << ans;
	return 0;
}


