#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n , m;
vector<pi> ans[N];

void solve(int x) {
	m = 1;
	ans[1].pb({1 , 2});
	for(int i = 3 ; i <= x ; i += 2 , m++) {
		for(int j = 1 ; j <= m ; j++) 
			ans[j].pb({j , i}) , ans[j].pb({j + m , i + 1});
		for(int j = 1 ; j <= m ; j++) 
			ans[m + 1].pb({j + m , i}) , ans[m + 1].pb({j , i + 1});
		ans[m + 1].pb({i , i + 1});
	}
}

int main() {
	cin >> n;
	if(n % 2) {
		solve(n - 1);
		for(int i = 1 ; i <= m ; i++) ans[i].pb({i , n});
	}
	else solve(n);
	cout << n / 2 << '\n';
	for(int i = 1 ; i <= m ; i++) {
		cout << n - 1 << '\n';
		for(auto x : ans[i]) cout << x.fi << ' ' << x.se << '\n';
	}
}

