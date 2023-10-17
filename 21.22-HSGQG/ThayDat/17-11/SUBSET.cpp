#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , d[105] , ans = 0;

int main() {
	cin >> n >> k;
	for(int i = 1 , x ; i <= n ; i++) cin >> x , d[x % k]++;
	for(int i = 1 ; i <= (k - 1) / 2 ; i++) ans += max(d[i] , d[k - i]);
	if(d[0]) ans++;
	if(k % 2 == 0 && d[k / 2]) ans++;
	cout << ans;
}

