#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

void file() {
	freopen("kcp.inp" , "r" , stdin);
	freopen("kcp.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , ans;

int main() {
	file();
	while(cin >> n) {
		ans = 1;
		for(int i = 2 ; i <= sqrt(n) ; i++) if(n % i == 0) {
			while(n % i == 0) n /= i;
			ans *= i;
		}
		ans *= n;
		cout << ans << '\n';
	}
	return 0;
}

