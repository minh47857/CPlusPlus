#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , a , b , c;

bool check(int a , int b , int c) {
	int t = 0;
	while(t <= c) {
		if((c - t) % b == 0) return true;
		t += a;
	}
	return false;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> a >> b >> c;
		cout << ((check(a , b , c)) ? "Yes\n" : "No\n");
	}
	return 0;
}

