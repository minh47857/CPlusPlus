#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("sxso.inp" , "r" , stdin);
	freopen("sxso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
vector<char> v;

int main() {
	file();
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++) 
		if(s[i] >= '0' && s[i] <= '9') v.pb(s[i]);
	sort(v.begin() , v.end() , greater<char>());
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] >= '0' && s[i] <= '9') {
			cout << v.back();
			v.pop_back();
		} else cout << s[i];
	return 0;
}

