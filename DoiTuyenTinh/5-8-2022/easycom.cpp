#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("easycom.inp" , "r" , stdin);
	freopen("easycom.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n;

bool sieve(int n) {
	for(int i = 2 ; i <= sqrt(n) ; i++) 
		if(n % i == 0) return false;
	return true;
}

bool check(int n) {
	for(int i = 2 ; i <= sqrt(n) ; i++)
		if(n % i == 0) {
			if(sieve(i) && sieve(n / i)) return true;
			else break;
		}
	return false;
}

int main() {
	file();
	cin >> t;
	while(t--) {
		cin >> n;
		if(check(n)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

