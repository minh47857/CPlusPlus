#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("chenh.inp" , "r" , stdin);
	freopen("chenh.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , ans = 1 , s;
map<int , int> d;
string str;

int main() {
	file();
	cin >> str;
	n = str.size();
	str = ' ' + str;
	for(int i = 1 ; i <= n ; i++) {
		s += ((str[i] == 'a') ? 1 : -1);
		if(!s) ans = i;
		if(d[s]) ans = max(ans , i - d[s]);
		else d[s] = i;
	}
	cout << ans;
	return 0;
}

