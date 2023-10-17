#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t , a[20] , n;

int main() {
	cin >> t;
	while(t--) {
		ll ans = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
			cin >> a[i];
		for(int i = 1 ; i <= n ; i++) {
			ll res = 0 , Pow = 1;
			for(int j = 1 ; j <= n ; j++) if(j != i) {
				int x = a[j];
				while(!(x % 2)) {
					Pow *= 2;
					x /= 2;
				}
				res += x;
			}
			res += a[i] * Pow;
			ans = max(ans , res);
		}
		cout << ans << '\n';
	}
}

