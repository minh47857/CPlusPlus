#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t , n , k , d , num[N] , a[N] , ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> t;
	while(t--) {
		set<pi> s;
		cin >> n >> k >> d;
		for(int i = 1 ; i <= n ; i++) {
			cin >> a[i];
			if(i <= d) num[a[i]]++;
		}
		for(int i = 1 ; i <= d ; i++)
			s.insert({a[i] , num[a[i]]});
		ans = s.size();
		for(int i = d + 1 ; i <= n ; i++) {
			s.erase({a[i - d] , num[a[i - d]]});
			num[a[i - d]]--;
			if(num[a[i - d]]) 
				s.insert({a[i - d] , num[a[i - d]]});
			if(num[a[i]]) 
				s.erase({a[i] , num[a[i]]});
			num[a[i]]++;
			s.insert({a[i] , num[a[i]]});
			ans = min(ans , int(s.size()));
		}
		for(int i = 1 ; i <= n ; i++)
			num[a[i]] = 0;
		cout << ans << '\n';
	}
	return 0;
}

