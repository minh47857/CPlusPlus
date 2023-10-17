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

int n , b[N];
ll ans;

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) cin >> b[i];
    ans = b[1] + b[n - 1];
    for(int i = 2; i < n; i++) {
        ans += min(b[i] , b[i - 1]);
    }
    cout << ans;
    return 0;
}
