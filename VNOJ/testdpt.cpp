#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int main() {
	int n , ans = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		ans += n / i;
	}
	cout << ans;
	return 0;
}

