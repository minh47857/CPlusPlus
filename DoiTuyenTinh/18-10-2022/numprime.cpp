#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("numprime.inp" , "r" , stdin);
	freopen("numprime.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

string s;
ll sum , res;

bool check(ll x) {
	if(x == 1) return false;
	for(int i = 2 ; i <= min(int(sqrt(x)) , N) ; i++)
		if(x % i == 0) return false;
	return true;
}

int main() {
	file();
	cin >> s;
	for(auto i : s) {
		sum = sum * 10 + i - '0';
		if(check(sum)) cout << sum << ' ' , res++;
	}
	if(!res) cout << -1;
	else cout << '\n' << res;
	return 0;
}

