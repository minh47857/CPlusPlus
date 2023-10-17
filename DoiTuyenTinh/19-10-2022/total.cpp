#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("total.inp" , "r" , stdin);
	freopen("total.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll k , ans;

int main() {
	file();
	cin >> k;
	k *= 2;
	for(int i = 1 ; i <= sqrt(k) ; i++) 
		if(k % i == 0 && abs(i - k / i) % 2)  ans++;
	cout << ans;
	return 0;
}

