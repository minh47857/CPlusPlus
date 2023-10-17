#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
#define Bit(x , k) ((x >> k) & 1)
using namespace std;

const int N = 35 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("sretan.inp" , "r" , stdin);
	freopen("sretan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k , s[N] , p;

int main() {
	file();
	cin >> k;
	for(int i = 1 ; i <= 30 ; i++) {
		s[i] = (1 << i) + s[i - 1];
		if(k > s[i]) p = i;
	}
	k -= s[p];
	for(int i = p + 1 ; i >= 1 ; i--) {
		if(k > (1 << (i - 1))) k -= (1 << (i - 1)) , cout << 7;
		else cout << 4;
	}
	return 0;
}

