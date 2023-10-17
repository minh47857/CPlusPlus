#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5; 
const ll base = 12345678910;

using namespace std;

int n;
ll a[N] , b[N] , res;
map<ll , int> f;

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> b[i];
		a[i] = a[i] + base;
		b[i] = b[i] + base + 1;
	}
	ll X = 0;
	f[0] = 1;
	for(int i = 1 ; i <= n ; i++) {
		X = X ^ a[i] ^ b[i];
		res += f[X];
		f[X]++;
	}
	cout << res;
	return 0;
}

