#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("pairing.inp" , "r" , stdin);
	freopen("pairing.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int a , b , c , d;

int main() {
	file();
	cin >> a >> b >> c >> d;
	cout << a % 2 + c % 2 + abs(b - a % 2 - (d - c % 2));
	return 0;
}

