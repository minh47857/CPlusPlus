#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t , A , O , X , n , bit[N];

int Bit(int x , int k) {
	return (x >> k) & 1;
}

void solve() {
	cin >> n >> A >> O >> X;
	memset(bit , 0 , sizeof(bit));
	for(int i = 0 , a , o , x ; i <= 30 ; i++) {
		a = Bit(A , i);
		o = Bit(O , i);
		x = Bit(X , i);
		if(a == 1) {
			if(o == 0 || n % 2 != x) {
				cout << -1 << '\n';
				return ;
			}
			else for(int j = 1 ; j <= n ; j++) bit[j] += (1 << i);
		}
		else if(o == 0) {
			if(a == 1 || x != 0) {
				cout << -1 << '\n';
				return ;
			}
		}
		else {
			if(n <= 2 && x != 1) {
				cout << -1 << '\n';
				return ;
			}
			else {
			    bit[2] += (1 << i);
				bit[3] += abs(x - 1) * (1 << i);
			}
		}	
	}
	for(int i = 1 ; i <= n ; i++) cout << bit[i] << ' ';
	cout << '\n';
}

int main() {
	cin >> t;
	while(t--) solve();
	return 0;
}

