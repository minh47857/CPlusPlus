#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pi pair<int , int>
#define pb push_back

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("ksnt.inp" , "r" , stdin);
	freopen("ksnt.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;

int main() {
	file();
	cin >> n;
	cout << n / 2 << '\n';
	while(n > 3) cout << 2 << ' ' , n -= 2;
	cout << n;
	return 0;
}

