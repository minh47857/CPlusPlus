#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("xh.inp" , "r" , stdin);
	freopen("xh.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , f[N];
pi a[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) cin >> x , a[i] = {x , i};
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++)
		f[i] = (a[i].se > a[i - 1].se ? f[i - 1] + 1 : 1) , ans = max(ans , f[i]);
	cout << n - ans;
	return 0;
}

