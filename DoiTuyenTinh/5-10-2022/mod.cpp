#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("mod.inp" , "r" , stdin);
	freopen("mod.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll a , b , c;

int main() {
	file();
	cin >> a >> b >> c;
	if(a > c) swap(a , c);
	if(b > c) swap(b , c);
	if(a > b) swap(a , b);
	cout << __gcd(c - b , b - a);
	return 0;
}

