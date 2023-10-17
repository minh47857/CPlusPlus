#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("delete.inp" , "r" , stdin);
	freopen("delete.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , ans = 0 , r[N] , l[N];
deque<ll> dq;
vector<ll> Q;

int main() {
	file();
	cin >> n;
	a[0] = a[n + 1] = inf;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	dq.pb(0);
	for(int i = 1 ; i <= n ; i++) {
		while(dq.size() && a[dq.back()] <= a[i]) dq.pop_back();
		l[i] = dq.back();
		dq.pb(i);
	}
	dq.clear() , dq.pb(n + 1);
	for(int i = n ; i >= 1 ; i--) {
		while(dq.size() && a[dq.back()] < a[i]) dq.pop_back();
		r[i] = dq.back();
		dq.pb(i);
	}
	for(int i = 1 ; i <= n ; i++) {
		if(r[i] == n + 1 || l[i] == 0) Q.pb(a[i]);
		else ans += min(a[l[i]] , a[r[i]]);
	}
	for(int i = 1 ; i < Q.size() - 1 ; i++) ans += min(Q[i - 1] , Q[i + 1]);
	cout << ans;
	return 0;
}

