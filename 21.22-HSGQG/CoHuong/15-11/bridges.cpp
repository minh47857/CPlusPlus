#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("bridges.inp" , "r" , stdin);
	freopen("bridges.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k;
ll ans = 0;
vector<ll> num;

void solve1() {
	sort(num.begin() , num.end());
	ll x = num[num.size() / 2];
	for(auto i : num) ans += abs(i - x);
	cout << ans;
}

int main() {
	file();
	cin >> k >> n;
	for(int i = 1 ; i <= n ; i++) {
		char st1 , st2;
		ll u , v;
		cin >> st1 >> u >> st2 >> v;
		if(st1 == st2) ans += abs(u - v);
		else ans++ , num.pb(u) , num.pb(v);
	}
	if(k == 1) solve1();
	return 0;
}

