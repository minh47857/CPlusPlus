#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("mass.inp" , "r" , stdin);
	freopen("mass.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
int n , pos[N];
vector<int> q;

int solve(int l , int r) {
	int res = 0;
	for(int i = l ; i <= r ; i++) {
		int tmp , hs = 0;
		if(s[i] == '(') tmp = solve(i + 1 , pos[i] - 1) , i = pos[i];
		else {
			if(s[i] == 'O') tmp = 16;
			if(s[i] == 'C') tmp = 12;
			if(s[i] == 'H') tmp = 1;
		}
		while(i < r && s[i + 1] >= '1' && s[i + 1] <= '9') hs = hs * 10 + s[i + 1] - '0' , i++;
		res += tmp * ((hs) ? hs : 1);
	}
	return res;
}

int main() {
	file();
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for(int i = 1 ; i <= n ; i++) {
		if(s[i] == '(') q.pb(i);
		if(s[i] == ')') pos[q.back()] = i , q.pop_back();
	}
	cout << solve(1 , n);
	return 0;
}

