#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , m , n , a[N];
multiset<pi> s;

void solve() {
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	s.clear() , s.insert({a[1] , 1});
	for(int i = 2 ; i <= n ; i++) 
		if(a[i] < (*s.begin()).fi) s.insert({a[i] , i});
	s.insert({-1 , n + 1});
	while(m--) {
		int k , d;
		cin >> k >> d;
		a[k]-= d;
		auto it = s.upper_bound({a[k] , k});
		if(it == s.end()) {cout << s.size() - 1 << ' ' ; continue;}
		it--;
		if((*it).se < k) {cout << s.size() - 1 << ' ' ; continue;}
		while(true) {
			auto it = s.lower_bound({a[k] , k});
			if((*it).se >= k) s.erase(it);
			else break;
		}
		s.insert({a[k] , k});
		cout << s.size() - 1 << ' ';
	}
	cout << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

