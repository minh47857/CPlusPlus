#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , s[N] , l[N] , r[N] , ans = 0;
deque<int> dq;

int main() {
	file();
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		n--;
		for(int i = 1 ; i <= n ; i++) s[i] = abs(a[i + 1] - a[i]);
		
		for(int i = 1 ; i <= n ; i++) {
			while(dq.size() && s[dq.back()] <= s[i]) dq.pop_back();
			if(dq.empty()) l[i] = 1;
			else l[i] = dq.back() + 1;
			dq.pb(i);
		}
		dq.clear();
		for(int i = n ; i >= 1 ; i--) {
			while(dq.size() && s[dq.back()] < s[i]) dq.pop_back();
			if(dq.empty()) r[i] = n;
			else r[i] = dq.back() - 1;
			dq.pb(i);
		}
		for(int i = 1 ; i <= n ; i++) {
			ans = ans + (i - l[i] + 1) * (r[i] - i + 1) * s[i];
		}
		cout << ans;
	return 0;
}

