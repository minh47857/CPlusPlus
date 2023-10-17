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

ll p , q , ans;

int main() {
	cin >> p >> q;
	for(int a = 0 ; a <= p ; a++)
		for(int b = 0 ; a + b <= p ; b++) {
			if(a * b == 0) ans += p - a - b + 1;
			else ans += min(p - a - b , q / (a * b)) + 1;
		}
	cout << ans;
	return 0;
}

