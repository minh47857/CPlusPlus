#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("catxau.inp" , "r" , stdin);
	freopen("catxau.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
bool c[30];
int ans= 1;

int main() {
	file();
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++) {
		if(c[s[i] - 'a']) {
			ans++;
			memset(c , 0 , sizeof(c));
		}
		c[s[i] - 'a'] = true;
	}
	cout << ans;
	return 0;
}

