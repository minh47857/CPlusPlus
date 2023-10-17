#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("sumseq0.inp" , "r" , stdin);
	freopen("sumseq0.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
ll a[N] , s[N] , ans;
map<ll , int> d;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , s[i] = s[i - 1] + a[i];
	d[0]++;
	for(int i = 1 ; i <= n ; i++)
		ans += d[s[i]] , d[s[i]]++;
	cout << ans;
	return 0;
}

