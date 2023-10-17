#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("homework.inp" , "r" , stdin);
	freopen("homework.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , a[N];
ll s;

int main() {
	file();
	cin >> n >> s;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++)
		if(a[i] <= s) s += a[i] , ans++;
		else break;
	cout << ans;
	return 0;
}

