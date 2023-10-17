#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("Seqstr.inp" , "r" , stdin);
	freopen("Seqstr.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , d[25];
long long ans;
string s[N];

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	for(int i = 1 ; i <= n ; i++) {
		ans += d[s[i].size()];
	    d[s[i].size()]++;
		if(i > k) d[s[i - k].size()]--;
	}
	cout << ans;
	return 0;
}

