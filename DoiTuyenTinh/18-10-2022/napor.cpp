#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)
#define pb push_back

using namespace std;
const int N = 1e2 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("napor.inp" , "r" , stdin);
	freopen("napor.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n;
string s[N];
vector<string> v;

bool cmp(string a , string b) {
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 0 ; j < s[i].size() ; j++) {
			if(s[i][j] < '0' || s[i][j] > '9') continue;
			string str = "";
			str += s[i][j];
			while(j + 1 < s[i].size() && s[i][j + 1] >= '0' && s[i][j + 1] <= '9') 
				str += s[i][j + 1] , j++;
			while(str.size() && str[0] == '0') str.erase(0 , 1);
			if(str.empty()) v.pb("0");
			else v.pb(str);
		}
	}
	sort(v.begin() , v.end() , cmp);
	for(auto x : v) cout << x << '\n';
	return 0;
}

