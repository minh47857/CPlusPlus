#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("tinhtong.inp" , "r" , stdin);
	freopen("tinhtong.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
string s , a[N];

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
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , reverse(a[i].begin() , a[i].end());
	for(int i = 1 ; i <= n ; i++) s = sum(s , a[i]);
	reverse(s.begin() , s.end());
	cout << s;
	return 0;
}

