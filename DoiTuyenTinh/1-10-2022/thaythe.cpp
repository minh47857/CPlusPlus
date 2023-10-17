#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("thaythe.inp" , "r" , stdin);
	freopen("thaythe.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s , s1 , s2;

int main() {
	file();
	getline(cin , s);
	cin >> s1 >> s2;
	for(int i = 0 ; i < s.size() ; i++) {
		string str = s.substr(i , s1.size());
		if(str == s1) cout << s2 , i += s1.size() - 1;
		else cout << s[i];
	}
	return 0;
}

