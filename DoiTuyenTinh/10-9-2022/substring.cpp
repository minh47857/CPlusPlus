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
	freopen("substring.inp" , "r" , stdin);
	freopen("substring.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string str;
int n , f[N];

int main() {
	file();
	cin >> str;
	n = str.size();
	str = ' ' + str;
	f[1] = 0;
	for(int i = 2 ; i <= n ; i++) {
		int k = f[i - 1];
		while(k && str[k + 1] != str[i]) k = f[k];
		if(str[k + 1] == str[i]) k++;
		f[i] = k;
	}
	if(n % (n - f[n]) == 0) cout << n / (n - f[n]);
	else cout << 1;
	return 0;
}

