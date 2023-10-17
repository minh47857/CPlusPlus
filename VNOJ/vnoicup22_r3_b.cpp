#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , q , f[N];
string str;

int main() {
	file();
	cin >> n >> q >> str;
	str = ' ' + str;
	for(int i = 1 ; i <= n ; i++) 
		f[i] = f[i - 1] + (str[i] == ')' && str[i - 1] == '(');
	while(q--) {
		int l , r;
		cin >> l >> r;
		cout << f[r] - f[l] << '\n';
	}
	return 0;
}

