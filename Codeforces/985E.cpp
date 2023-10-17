#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , k , d , a[N] , dp[N] , s[N];

int main() {
	cin >> n >> k >> d;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	int j = 1;
	dp[0] = 1;
	s[0] = 1;
	for(int i = 1 ; i <= n ; i++) {
		while(j < i && a[i] - a[j] > d) j++;
		if(i - j + 1 < k) dp[i] = 0;
		else {
			dp[i] = ((s[i - k] > s[j - 2]) ? 1 : 0);
		}
		s[i] = s[i - 1] + dp[i];
	}
	cout << ((dp[n] == 1) ? "YES" : "NO");
}

