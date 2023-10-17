#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<char , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s , l;
vector<pi> str1 , str2;
vector<char> ans;

int main() {
	getline(cin , s);
	getline(cin , l);
	for(int i = 0 ; i < s.size() ; i++) {
		int dem = 1;
		while(i != s.size() - 1 && s[i] == s[i + 1]) dem++ , i++;
		str1.pb({s[i] , dem});
	}
	for(int i = 0 ; i < l.size() ; i++) {
		int dem = 1;
		while(i != l.size() - 1 && l[i] == l[i + 1]) dem++ , i++;
		str2.pb({l[i] , dem});
	}
	for(int i = 0 ; i < str1.size() ; i++) 
		if(str1[i].se * 2 == str2[i].se) ans.pb(str1[i].fi);
		sort(ans.begin() , ans.end());
	ans.erase(unique(ans.begin() , ans.end()) , ans.end());
//	for(int i = 0 ; i < str1.size() ; i++) cout << str2[i].fi << ' ' << str2[i].se << '\n';
	
	for(auto x : ans) cout << x;
	return 0;
}

