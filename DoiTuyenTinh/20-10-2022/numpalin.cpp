#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("numpalin.inp" , "r" , stdin);
	freopen("numpalin.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n;
string s;

bool check(string s) {
	if(s == "1") return false;
	bool ok = 1;
	for(int i = 1 ; i < s.size() ; i++) ok &= (s[i] == '0');
	if(s[0] == '1' && ok) return true;
	return false;
}

void solve() {
	string ans1 , ans2 , ans3;
	n = s.size();
	if(check(s)) {
		for(int i = 1 ; i < n ; i++) cout << 9;
		cout << '\n';
		return;
	}
	s = ' ' + s;
	for(int i = 1 ; i <= (n + 1) / 2 ; i++) ans1 += s[i];
	for(int i = (n + 1) / 2 , nho = 1 ; i >= 1 ; i--) {
		if(s[i] - '0' == 0 && nho) ans2 += '9';
		else ans2 += (s[i] - nho) , nho = 0; 
	}
	ans3 = ans2;
	reverse(ans3.begin() , ans3.end());
	if(n % 2) ans2.erase(0 , 1);
	s.erase(0 , 1);
	string tmp1 = ans3 + ans2;
	ans3 = ans1;
	reverse(ans3.begin() , ans3.end());
	if(n % 2) ans3.erase(0 , 1);
	string tmp2 = ans1 + ans3;
	if(max(tmp1 , tmp2) <= s) cout << max(tmp1 , tmp2);
	else cout << min(tmp1 , tmp2);
	cout << '\n';
}

int main() {
	file();
	while(cin >> s) solve();
	return 0;
}

