#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e2 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("napor.inp" , "r" , stdin);
	freopen("napor.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
string s[N];
vector<string> ans;

bool cmp(string a , string b) {
	if(a.size() < b.size()) return true;
	if(a.size() == b.size()) return a < b;
	return false;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j < s[i].size() ; j++) {
			string t = "";
			while(j < s[i].size() && s[i][j] >= '0' && s[i][j] <= '9') t += s[i][j] , j++;
			if(t == "") continue;
			while(t.size() && t[0] == '0') t.erase(0 , 1);
			if(t == "") ans.pb("0");
			else ans.pb(t);
		}
	sort(ans.begin() , ans.end() , cmp);
	for(auto x : ans) cout << x << '\n';
	return 0;
}

