#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , A1 , B1 , A2 , B2 , a[N];

int main() {
	cin >> n >> k >> A1 >> B1 >> A2 >> B2;
	for(int i = 1 ; i <= n ; i++) a[i] = i;
	while(k--) {
		reverse(a + A1 , a + B1 + 1);
		reverse(a + A2 , a + B2 + 1);
	//	for(int i = A1 ; i <= B1 - (B1 - A1 + 1) / 2; i++) swap(a[i] , a[B1 - i + A1]);
	//	for(int i = A2 ; i <= B2 - (B2 - A2 + 1) / 2 ; i++) swap(a[i] , a[B2 - i + A2]);
	}
	for(int i = 1 ; i <= n ; i++) cout << a[i] << '\n';
	return 0;
}

