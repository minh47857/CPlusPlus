#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 1e6 + 5 , MOD = 1e9 + 7 , inf1 = LLONG_MIN , inf2 = LLONG_MAX;

void file() {
    freopen("MAXDIS.inp" , "r" , stdin);
	freopen("MAXDIS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , L , R , a[N] , ans , num;

int main() {
	file();
	cin >> n >> L >> R;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	if(L == inf1 && R == inf2) {
		if(a[1] > 0) cout << L;
		else cout << R;
		return 0;
	} // magic =))
	if(L <= a[1]) 
		ans = a[1] - L , num = L;
	for(int i = 1 ; i < n ; i++) {
		ll s2 = (a[i] + a[i + 1] + 1) / 2;
		ll s1 = (a[i] + a[i + 1]) / 2;
		if(s1 >= L && s1 <= R && s1 - a[i] >= ans) 
			ans = s1 - a[i] , num = s1;
		if(s2 >= L && s2 <= R && a[i + 1] - s2 >= ans)
			ans = a[i + 1] - s2 , num = s2;
		if(a[i] <= L && a[i + 1] >= L && min(L - a[i] , a[i + 1] - L) >= ans)
			ans = min(L - a[i] , a[i + 1] - L) , num = L;
		if(a[i] <= R && a[i + 1] >= R && min(R - a[i] , a[i + 1] - R) >= ans)
			ans = min(R - a[i] , a[i + 1] - R) , num = R;
	}
	if(R >= a[n]) {
		if(R - a[n] >= ans) 
			ans = R - a[n] , num = R;
	}
	
	cout << num;
	return 0;
}



