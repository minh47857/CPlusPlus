#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("namenum.inp" , "r" , stdin);
	freopen("namenum.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;
string s[15] , a[N];

int main() {
	file();
	for(int i = 0 ; i <= 9 ; i++) cin >> s[i];
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		string res = "";
		for(auto x : a[i]) res = max(res , s[x - '0']);
		cout << res << '\n';
	}
	return 0;
}

