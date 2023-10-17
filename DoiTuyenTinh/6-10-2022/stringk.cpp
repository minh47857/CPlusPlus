#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("stringk.inp" , "r" , stdin);
	freopen("stringk.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
string s;

int main() {
	file();
	cin >> n >> s;
	s = ' ' + s;
	for(int k = 1 ; k <= n ; k++) {
		bool ok = true;
		vector<string> v;
		for(int i = 1 ; i <= n - k + 1 ; i++) v.pb(s.substr(i , k));
		sort(v.begin() , v.end());
		for(int i = 1 ; i < v.size() ; i++)
			if(v[i] == v[i - 1]) ok = false;
		if(ok) {
			cout << k;
			return 0;
		}
	}
}

