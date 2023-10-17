#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int main() {
	int a , b;
	cin >> a >> b;
	if(a == 9 && b == 1) cout << 9 << ' ' << 10;
	else if(a == b) cout << a << 0 << ' ' << b << 1;
		 else if(a + 1 == b) cout << a << ' ' << b;
			  else cout << -1;
}

