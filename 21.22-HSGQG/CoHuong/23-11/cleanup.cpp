#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 4e4 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("cleanup.in" , "r" , stdin);
	freopen("cleanup.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , dp[N] , a[N] , last[N];
set<int> Q;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		if(last[a[i]]) Q.erase(-last[a[i]]);
		last[a[i]] = i;
		Q.insert(-i);
		dp[i] = min(int(Q.size()) * int(Q.size()) , i);
		int cnt = 0;
		for(auto x : Q) {
			if(cnt * cnt > i) break;
			dp[i] = min(dp[i] , dp[-x] + cnt * cnt);
			cnt++;
		}
	}
	cout << dp[n];
	return 0;
}


