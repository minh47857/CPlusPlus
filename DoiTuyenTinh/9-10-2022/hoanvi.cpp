#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("hoanvi.inp" , "r" , stdin);
	freopen("hoanvi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , sum , b[N] , a[N];

void solve1() {
	for(int i = 1 ; i < n ; i++) sum += b[i];
	sum = n * (n + 1) - sum;
	for(int i = 2 ; i < n ; i += 2) sum += b[i - 1] - b[i];
	a[1] = sum / 2;
	for(int i = 2 ; i <= n ; i++) a[i] = b[i - 1] - a[i - 1];
	for(int i = 1 ; i <= n ; i++) cout << a[i] << ' ';
}
//
//void solve2() {
//	for(int i = 1 ; i < n ; i++) 
//}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i < n ; i++) cin >> b[i];
	if(n % 2) solve1();
	//else solve2();
	return 0;
}

