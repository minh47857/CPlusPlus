#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("khoa.inp" , "r" , stdin);
	freopen("khoa.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans;
string str;
vector<int> res;

int main() {
	file();
	cin >> str;
	n = str.size();
	str = ' ' + str;
	
	for(int i = 1 ; i <= n ; i++) {
		string s , ss;
		s = str.substr(i , n - i + 1) + str.substr(1 , i - 1);
		ss = s;
		reverse(ss.begin() , ss.end());
		ans += s==ss;
		if(ss == s) res.pb(i - 1);
	}
	if(!ans) cout << -1;
	else {
		cout << ans << '\n';
		for(int i : res) {
			cout << (!i ? n : i) << ' ' << i + 1 << '\n';
		}
	}
	return 0;
}

