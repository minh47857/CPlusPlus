#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("fnum.inp" , "r" , stdin);
	freopen("fnum.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
int k;

int main() {
	file();
	cin >> s;
	for(auto i : s) k += (i - '0');
	while(k >= 10) {
		int x = k;
		k = 0;
		while(x) {
			k += x % 10;
			x /= 10;
		}
	}
	cout << k;
	return 0;
}

