#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("BITOPERATORS.in" , "r" , stdin);
	freopen("BITOPERATORS.ok" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , q , k;
string str;

int Bit(int x , int k) {
	return (x >> k) & 1;
}

int main() {
	file();
	cin >> n >> q;
	while(q--) {
		cin >> str >> k;
		if(str == "ENABLE") n = n | (1 << k) , cout << n << '\n';
		if(str == "DISABLE") {
			if(Bit(n , k)) n = n ^ (1 << k);
			cout << n << '\n';
		}
		if(str == "FLIP") n = n ^ (1 << k) , cout << n << '\n';
		if(str == "CHECK") {
			if(Bit(n , k)) cout << "ON" << '\n';
			else cout << "OFF" << '\n';
		}
	}
	return 0;
}


