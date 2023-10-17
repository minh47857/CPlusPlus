#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("twins.inp" , "r" , stdin);
	freopen("twins.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , c[N];
ll ans;

int main() {
	file();
	cin >> n >> k;
	for(int i = 2 ; i <= sqrt(n) ; i++)
		if(!c[i]) for(int j = i * i ; j <= n ; j += i) c[j] = 1;
	for(int i = 2 ; i <= n - k; i++) 
		if(!c[i] && !c[i + k]) ans++;
	cout << ans;
}

