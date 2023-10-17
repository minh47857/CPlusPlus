#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("reward.inp" , "r" , stdin);
	freopen("reward.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N];
ll S , s[N] , ans;

int main() {
	file();
	cin >> n >> S;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , s[i] = s[i - 1] + a[i];
	n++;
	sort(s + 1 , s + n + 1);
	for(int i = 2 ; i <= n ; i++) {
		int d = 1 , c = i - 1 , g , res = -1;
		while(d <= c) {
			g = (d + c) / 2;
			if(s[g] < s[i] - S) res = g , d = g + 1;
			else c = g - 1;
		}
		if(res != -1) ans += res;
	}
	cout << ans;
	return 0;
}

