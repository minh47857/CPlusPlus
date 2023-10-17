#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e16;

void file() {
    freopen("teleport.inp" , "r" , stdin);
	freopen("teleport.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll k , n , m , A[N] , B[N] , sA[N] , sB[N];
ll solve(int n , ll a[] , ll s[] ){
	ll ans = inf;
	for(int i = 1 ; i <= n ; i++) {
		ll res = 0;
		res = s[n] - s[i] - a[i] * (n - i);
		int d = 1 , c = i - 1 , kq = -1 , g;
		while(d <= c) {
			g = (d + c) / 2;
			if(a[g] * 2 >= a[i]) kq = g , c = g - 1;
			else d = g + 1;
		}
		if(kq != -1) {
			res = res + a[i] * (i - kq + 1) - (s[i] - s[kq - 1]);
			res = res + s[kq - 1];
		}
		else res += s[i - 1];
		ans = min(ans , res);
	}
	return ans;
}

int main() {
	file();
	cin >> k;
	for(int i = 1 , x; i <= k ; i++) {
		cin >> x;
		if(x > 0) A[++n] = x;
		else B[++m] = abs(x);
	}
	sort(A + 1 , A + n + 1);
	sort(B + 1 , B + m + 1);
	for(int i = 1 ; i <= n ; i++) sA[i] = sA[i - 1] + A[i];
	for(int i = 1 ; i <= m ; i++) sB[i] = sB[i - 1] + B[i];
    cout << min(solve(n , A , sA) + sB[m] , solve(m , B , sB) + sA[n]);
	return 0;
}


