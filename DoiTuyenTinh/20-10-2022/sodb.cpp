#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)
#define pb push_back

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("sodb.inp" , "r" , stdin);
	freopen("sodb.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , a[N] , ans;
vector<int> res;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 2 ; i <= n ; i++) ans = __gcd(ans , a[i] - a[i - 1]);
	for(int i = 2 ; i <= sqrt(ans) ; i++) {
		if(1LL * i * i == ans && ans % i == 0) res.pb(i);
		else if(ans % i == 0) res.pb(i) , res.pb(ans / i);
	}
	res.pb(ans);
	sort(res.begin() , res.end());
	for(auto k : res) cout << k << '\n';
	return 0;
}

