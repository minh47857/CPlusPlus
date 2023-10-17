#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("index.inp" , "r" , stdin);
	freopen("index.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N] , l[N] , r[N];
ll ans;
deque<int> dq;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		while(dq.size() && a[i] < a[dq.back()]) dq.pop_back();
		l[i] = dq.size() ? i - dq.back() - 1 : i - 1;
		dq.push_back(i);
	}
	while(dq.size()) dq.pop_back();
	for(int i = n ; i >= 1 ; i--) {
		while(dq.size() && a[i] < a[dq.back()]) dq.pop_back();
		r[i] = dq.size() ? dq.back() - i - 1 : n - i;
		dq.push_back(i);
	}
	for(int i = 1 ; i <= n ; i++) ans = max(ans , 1LL * l[i] * r[i]);
	cout << ans;
	return 0;
}
