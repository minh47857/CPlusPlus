#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 55 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("apples.in" , "r" , stdin);
	freopen("apples.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll t , n , a , c[N];

void solve() {
	cin >> n >> a;
	if(n == 2) {
		if(a % 5 != 0) cout << -1;
		else cout << a << ' ' << 3 * a / 5;
	}
	else if(n == 3) {
		if(a % 13 != 0) cout << -1;
		else cout << a << ' ' << 7 * a / 13 << ' ' << 4 * a / 13;
	}
	else {
		bool check = true;
		c[1] = a;
		for(int i = 2 ; i <= n ; i++) c[i] = c[i - 1] / 2 + 1;
		for(int i = 1 ; i <= n ; i++) {
			ll sum = 0;
			for(int j = 1 ; j <= n ; j++) 
				if(i != j) {
					sum += c[j];
					c[j] = c[j] * 2;
				}
			c[i] -= sum;	
		}
		for(int i = 2 ; i <= n ; i++) if(c[i] != c[i - 1]) check = false;
		if(check) {
			cout << a << ' ' ;
		    for(int i = 2 ; i <= n ; i++) a = a / 2 + 1 , cout << a << ' ';
		}
		else cout << -1;	
	}
	cout << '\n';
}

int main() {
	file();
 cin >> t;
 while(t--) solve();
}

