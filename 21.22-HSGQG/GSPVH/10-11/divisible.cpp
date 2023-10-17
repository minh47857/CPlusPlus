#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define lb long double
#define pb push_back
#define pi pair<int , int>

const lb eps = 1e-6;

void file() {
	freopen("divisible.inp" , "r" , stdin);
	freopen("divisible.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k[55] , n;
lb ans = 0 , p;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> k[i] , k[i]++;
	for(int i = 1 ; i <= n ; i++) ans = ans + 1.0 * 1 / k[i];
	p = 1;
	if(abs(ans - 1) <= eps) {
		bool check = true;
		sort(k + 1 , k + n + 1);
		for(int i = 2 ; i <= n ; i++) if(k[i] == k[i - 1]) check = false;
		cout << ((check) ? "Yes" : "No");
	}
	else {
		if(ans > 1) cout << "No";
	    else cout << "Yes";
	}
	
    return 0;
}

