#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("ThreeGCD.inp" , "r" , stdin);
	freopen("ThreeGCD.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int x , y;

int main() {
	file();
	cin >> x >> y;
	for(int d = y ; d >= 1 ; d--) {
		int k = y / d;
		if(d * k >= x && d * (k - 1) >= x && d * (k - 2) >= x) {
			cout << d;
			return 0;
		}
	}
}


