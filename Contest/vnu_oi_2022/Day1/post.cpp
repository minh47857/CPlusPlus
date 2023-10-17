#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n , s1 , s2 , a[N];

bool check(int x) {
	if(abs(s1 - s2) > x) return false;
	int p1 = s1 , p2 = s2;
	for(int i = 1 ; i <= n ; i++) {
		if(abs(a[i] - p2) > x && abs(a[i] - p1) > x) return false;
		if(abs(a[i] - p2) <= x) p1 = a[i];
		else p2 = a[i]; 
	}
	return true;
}

int main() {
	cin >> n >> s1 >> s2;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	int d = 0 , c = inf , ans , g;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) c = g - 1 , ans = g;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}

