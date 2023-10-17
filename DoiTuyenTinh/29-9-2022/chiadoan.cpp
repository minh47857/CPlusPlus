#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e2 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("chiadoan.inp" , "r" , stdin);
	freopen("chiadoan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , d[N];
ll s;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		ll tmp = 0 , res = 1;
		s += a[i];
		memset(d , 0 , sizeof(d));
		d[i] = 1;
		for(int j = i + 1 ; j <= n ; j++) {
			tmp += a[j];
			if(tmp == s) d[j] = 1 , res++ , tmp = 0;
		}
		if(!tmp) {
			cout << res << ' ' << s << '\n';
			if(!d[n]) 
				for(int i = n - 1 ; i >= 1 ; i--) 
					if(d[i]) {d[i] = 0;break;}
			d[n] = 1;
			for(int x = 1 ; x <= n ; x++) {
				cout << a[x] << ' ';
				if(d[x]) cout << '\n';
			}
			return 0;
		}
		
	}
}

