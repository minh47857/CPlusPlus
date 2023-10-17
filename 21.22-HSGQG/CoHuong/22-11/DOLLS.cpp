#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("DOLLS.inp" , "r" , stdin);
	freopen("DOLLS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , a[N] , ans = 0;
multiset<int> s;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1 , greater<int>());
	for(int i = 1 ; i <= n ; i++) {
		if(s.empty() || *s.rbegin() < a[i] + k) {
			ans += a[i];
			s.insert(a[i]);
		}
		else {
            auto it = s.end();
            it--;
			s.erase(it);
			s.insert(a[i]);
	    }
	}
	cout << ans;
	return 0;
}

