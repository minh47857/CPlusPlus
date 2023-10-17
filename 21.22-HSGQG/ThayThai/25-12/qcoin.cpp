#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 6005 , MOD = 1e9 + 7;

int n , s , a[N] , b[N] , ans = 0 , f[N];
vector<int> res;

void Plus(int&x , int y) {
	x += y;
	if(x >= MOD) x -= MOD;
}

int solve(int m , int sum) {
	f[0] = 1;
	for(int i = 1 ; i <= sum ; i++) 
		f[i] = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] < m) continue;
		for(int j = sum ; j >= 1 ; j--)
			if(j - b[i] >= 0) Plus(f[j] , f[j - b[i]]);
	}
	return f[sum];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> s;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i];
	for(int i = 1 ; i <= s ; i++) 
		if(s % i == 0) res.pb(i);
	for(auto x : res) 
		Plus(ans , solve(x , s / x)) ;
	cout << ans;
	return 0;
}

