#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t;
string s;

int main() {
	cin >> t;
	while(t--) {
		ll ans = 0;
		vector<int> C[30];
		cin >> s;
		s = ' ' + s;
		for(int i = 1 ; i < s.size() ; i++) 
			C[s[i] - 'a'].pb(i);
		for(int i = 0 ; i < 26 ; i++) {
			for(int j = 0 , l , r ; j < C[i].size() ; j++) {
				if(j == 0) l = 0;
				else l = C[i][j - 1];
				if(j == C[i].size() - 1) r = s.size();
				else r = C[i][j + 1];
				ans += (1LL * (C[i][j] - l) * (r - C[i][j]));
			}
		}
		cout << ans << '\n';
	}
}

