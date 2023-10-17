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

string s;
int n , d[35];
vector<pi> V;

void solve(int len) {
	vector<pi> ans;
	int res = 0;
	for(auto x : V) {
		res +=  (x.se + len - 1) / len;
		ans.pb({x.fi , (x.se + len - 1) / len});
	}
	if(res <= n) {
		cout << len << '\n';
		for(auto x : ans) for(int i = 1 ; i <= x.se ; i++) cout << char(x.fi + 'a');
		for(int i = 1 ; i <= n - res ; i++) cout << char(V[0].fi + 'a');
		exit(0);
	}
}

int main() {
	cin >> s >> n;
	for(int i = 0 ; i < s.size() ; i++) d[s[i] - 'a']++;
	for(int i = 0 ; i < 30 ; i++) if(d[i]) V.pb({i , d[i]});
	
	for(int i = 1 ; i <= s.size() ; i++) solve(i);
	cout << -1;
	return 0;
}

