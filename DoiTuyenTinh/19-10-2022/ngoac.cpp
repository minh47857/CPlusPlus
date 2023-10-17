#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("ngoac.inp" , "r" , stdin);
	freopen("ngoac.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , ans , s , pos , l;
string str;

int main() {
	file();
	cin >> str;
	n = str.size();
	str = ' ' + str;
	l = 1;
	for(int i = 1 ; i <= n ; i++) {
		s += ((str[i] == '(') ? 1 : -1);
		if(s == 0) if(ans < i - l + 1) ans = i - l + 1 , pos = l;
		if(s < 0) {
		 	l = i + 1;
		 	s = 0;
		} 
	}
	if(!ans) cout << -1;
	else cout << str.substr(pos , ans);
	return 0;
}

