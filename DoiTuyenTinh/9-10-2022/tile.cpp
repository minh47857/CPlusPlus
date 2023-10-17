#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 255 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("tile.inp" , "r" , stdin);
	freopen("tile.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , x;
string f[N];

string sum(string x , string y) {
	string res = "";
	int rem = 0 , num;
	while(x.size() > y.size()) y += '0';
	while(x.size() < y.size()) x += '0';
	for(int i = 0 ; i < x.size() ; i++) {
		num = x[i] - '0'+ y[i] - '0' + rem;
		res += (num % 10 + '0');
		rem = num / 10;
	}
	if(rem) res += '1';
	return res;
} 

int main() {
	file();
	f[0] = '1' , f[1] = '1';
	for(int i = 2 ; i <= 250 ; i++) f[i] = sum(sum(f[i - 2] , f[i - 2]) , f[i - 1]);
	while(cin >> x) {
		string ans = f[x];
		reverse(ans.begin() , ans.end());
		cout << ans << '\n';
	}
	return 0;
}

