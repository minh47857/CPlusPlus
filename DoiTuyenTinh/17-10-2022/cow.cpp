#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("cow.inp" , "r" , stdin);
	freopen("cow.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
ll l , ans;

int main() {
	file();
	cin >> s;
	for(int i = 0 ; i < s.size() - 1 ; i++) {
		if(s[i] == '(' && s[i + 1] == '(') l++;
		if(s[i] == ')' && s[i + 1] == ')') ans += l;
	}
	cout << ans;
	return 0;
}

