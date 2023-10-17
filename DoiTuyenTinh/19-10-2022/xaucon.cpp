#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("xaucon.inp" , "r" , stdin);
	freopen("xaucon.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k , p , f[N];
ll ans;
string s;

int main() {
	file();
	cin >> k >> s;
	s = ' ' + s;
	f[0] = 1;
	for(int i = 1 ; i < s.size() ; i++) {
		p = p + (s[i] == '1');
		if(p >= k) ans += f[p - k];
		f[p]++;
	}
	cout << ans;
	return 0;
}	

