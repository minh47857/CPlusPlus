#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
#define ii array<int , 3>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ii s , f , ans;
vector<ii> pre , suf;

int dist(ii u , int P) {
	return min({abs(u[0] - P) , abs(u[1] - P) , abs(u[2] - P)});
}

void calc(ii&u , vector<ii>& v) {
	sort(u.begin() , u.end());
	v.pb(u);
	if(u[2] - u[1] == u[1] - u[0]) return;
	u[0] = 2 * u[1] - u[0];
	int d1 = dist(u , 5e5);
	u[0] = 2 * u[1] - u[0];
	
	u[2] = 2 * u[1] - u[2];
	int d2 = dist(u , 5e5);
	u[2] = 2 * u[1] - u[2];
	
	if(d1 < d2) u[0] = 2 * u[1] - u[0];
	else u[2] = 2 * u[1] - u[2];
	calc(u , v);
}

int diff(ii a , ii b) {
	int res = (a[0] != b[0]) + (a[1] != b[1]) + (a[2] != b[2]);
	return res;
}

int main() {
	cin >> s[0] >> s[1] >> s[2];
	cin >> f[0] >> f[1] >> f[2];
	ans = s;
	calc(s , pre);
	calc(f , suf);
	if((s[1] - s[0] != f[1] - f[0]) || (s[0] - f[0]) % (2 * (s[1] - s[0])) != 0) {
		cout << -1;
		return 0;
	}
	reverse(pre.begin() , pre.end());
	pre.pop_back();
	reverse(pre.begin() , pre.end());
	suf.pop_back();
	reverse(suf.begin() , suf.end());
	sort(s.begin() , s.end()); sort(f.begin() , f.end());
	while(diff(s , f)) {
		if(s[0] < f[0]) {
			s[0] = 2 * s[2] - s[0];
			pre.pb(s);
			s[1] = 2 * s[2] - s[1];
			pre.pb(s);
		}
		else {
			s[1] = 2 * s[0] - s[1];
			pre.pb(s);
			s[2] = 2 * s[0] - s[2];
			pre.pb(s);
		}
		sort(s.begin() , s.end());
	}
	for(auto i : suf) pre.pb(i);
	cout << pre.size() << '\n';
	for(auto i : pre) {
		sort(i.begin() , i.end());
		while(diff(ans , i) != 1) 
			next_permutation(i.begin() , i.end());
		ans = i;
		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	}
}

