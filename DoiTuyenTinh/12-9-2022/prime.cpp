#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , inf = 1e9 + 7 , M = 1e6;

void file() {
	freopen("prime.inp" , "r" , stdin);
	freopen("prime.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string str;
ll num , ans;

int main() {
	file();
	cin >> str;
	for(char i : str) {
		bool ok = true;
		num = num * 10 + i - '0';
		if(num == 1) continue;
		int p = sqrt(num);
		int Max = min(M , p);
		for(int j = 2 ; j <= Max ; j++) if(num % j == 0) ok = false;
		if(ok) ans++ , cout << num << ' ';
	}
	if(!ans) cout << -1;
	else cout << '\n' << ans;
}

