#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("chiadoan.inp" , "r" , stdin);
	freopen("chiadoan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
ll s[N] , pre[N], ans;

int main() {
	file();
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) 
		cin >> x , s[i] = s[i - 1] + x;
	if(s[n] % 3) {
		cout << 0;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++) 
		pre[i] = pre[i - 1] + (s[i] * 3 == s[n]);
	for(int i = n - 1 ; i >= 2 ; i--) 
		if((s[n] - s[i]) * 3 == s[n])  ans += pre[i - 1];
	cout << ans;
	return 0;
}

