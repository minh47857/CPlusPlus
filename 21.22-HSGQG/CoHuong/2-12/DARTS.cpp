#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("DARTS.inp" , "r" , stdin);
	freopen("DARTS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N] , ans = 0;
vector<int> s;

int main() {
	file();
	cin >> n >> m;
	a[0] = 0;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 0 ; i <= n ; i++)
		for(int j = i ; j <= n ; j++)
			s.pb(a[i] + a[j]);
	sort(s.begin() , s.end());
	for(int i = 0 ; i <= n ; i++)
		for(int j = i ; j <= n ; j++) {
			int d = 0 , c = s.size() - 1 , g , res = -1;
			while(d <= c) {
				g = (d + c) / 2;
				if(s[g] <= m - (a[i] + a[j])) res = g , d = g + 1;
				else c = g - 1;
			}
			if(res != -1) ans = max(ans , s[res] + a[i] + a[j]);
		}
	cout << ans;
	return 0;
}


