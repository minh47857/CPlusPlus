#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("hopqua.inp" , "r" , stdin);
	freopen("hopqua.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N];

bool check(int x) {
	ll tmp = 0;
	for(int i = 1 ; i <= m ; i++)
		tmp += (a[i] + x - 1) / x;
	return tmp <= n;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) cin >> a[i];
	int d = 1 , c = 1e9 , g , res;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) res = g , c = g - 1;
		else d = g + 1;
	}
	cout << res;
}

