#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , K = 35;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , ans , a[N] , f[K];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] % 2 == 0) ans = (ans + f[k - 1]) % MOD;
        for(int j = k; j >= 2; j--) f[j] =(f[j] + f[j - 1]) % MOD;
        if(a[i]) f[1]++;
    }
    cout << ans;
}
