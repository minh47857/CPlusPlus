#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e7 + 5 , M = 1e7 , inf = 1e9;

void file() {
	freopen("khoaso.inp" , "r" , stdin);
	freopen("khoaso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n;
pi ans;

int main() {
	file();
	cin >> n;
	for(int i = 2 ; i <= n ; i++) {
		if(n % i == 0) ans.fi++ , ans.se += i;
		while(n % i == 0) n /= i;
	} 
	cout << ans.fi << ' ' << ans.se;
	return 0;
}

