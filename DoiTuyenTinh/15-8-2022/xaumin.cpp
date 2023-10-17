#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("xaumin.inp" , "r" , stdin);
	freopen("xaumin.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k , l = -1;
string str;

int main() {
	file();
	cin >> k >> str;
	while(k) {
		char res = '9';
		for(int i = l + 1 ; i <= str.size() - k ; i++) 
			if(str[i] < res) res = str[i] , l = i;
		cout << res;
		k--;
	}
	return 0;
}

