#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , M = 1e6 , inf = 1e9 + 7;

void file() {
	freopen("goldbach.inp" , "r" , stdin);
	freopen("goldbach.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , c[N];

void sieve() {
	for(int i = 2 ; i <= sqrt(M) ; i++)
		if(!c[i]) for(int j = i * i ; j <= M ; j += i) c[j] = 1;
}

int main() {
	file();
	sieve();
	cin >> n;
	for(int i = 2 ; i <= n / 2 ; i++) ans += (!c[i] && !c[n - i]);
	cout << ans;
	return 0;
}

