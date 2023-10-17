#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("matkhau.inp" , "r" , stdin);
	freopen("matkhau.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string s;
int ans;

int convert(string x) {
	int p = 0;
	for(int i = 0 ; i < x.size() ; i++) 
		if(x[i] < '0' || x[i] > '9') return 0;
	for(int i = 0 ; i < x.size() ; i++)
		p = p * 10 + x[i] - '0';
	for(int i = 2 ; i <= sqrt(p) ; i++)
		if(p % i == 0) return 0;
	return p;
}

int main() {
	file();
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++) 
		for(int l = 1 ; l <= 5 ; l++) {
			if(i + l - 2 > s.size()) continue;
			ans = max(ans , convert(s.substr(i , l)));
		}
	cout << ans;
	return 0;
}

