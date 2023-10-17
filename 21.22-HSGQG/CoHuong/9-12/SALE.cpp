#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("SALE.inp" , "r" , stdin);
	freopen("SALE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , p;

int main() {
	file();
	cin >> n >> k >> p;
	cout << (n / (k + 1) * k + n - n / (k + 1) * (k + 1)) * p;
    return 0;
}


