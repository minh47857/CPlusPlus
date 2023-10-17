#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e4 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , k;
string s[N];
pi f[N];

void file() {
	freopen("sell.inp" , "r" , stdin);
	freopen("sell.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string Plus(string a , string b) {
	string res = "";
	for(int i = 0 , tmp , nho = 0; i < 2000 ; i++) {
		tmp = a[i] - '0' + b[i] -'0' + nho;
		res += (tmp % k + '0');
		nho = tmp / k;
	}
	return res;
}

int Count(string a) {
	int res = 0;
	for(int i = 0 ; i < a.size() ; i++)
		res = res + (a[i] - '0');
	return res;
}

int main() {
	file();
	cin >> k >> n;
	s[1] += '1' , s[2] += '1';
	for(int j = 2 ; j <= 2000 ; j++) 
		s[1] += '0' , s[2] += '0';
	f[1] = {1 , 1} , f[2] = {1 , 2};
	for(int i = 3 ; i <= n ; i++) {
		s[i] = Plus(s[i - 1] , s[i - 2]);
		f[i] = {Count(s[i]) , i};
	}
	sort(f + 1 , f + n + 1);
	for(int i = 1 ; i <= n ; i++)
		cout << f[i].se << ' ';
	return 0;
}

