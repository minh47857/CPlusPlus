#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 5e4 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("primemost.inp" , "r" , stdin);
	freopen("primemost.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int l , r , res , c[N];

int calc(int x) {
	int tmp = 0;
	while(x) tmp += (x % 10) * (x % 10) , x /= 10;
	return tmp;
}

int main() {
	file();
	cin >> l >> r;
	c[1] = 1;
	for(int i = 2 ; i <= sqrt(50000) ; i++)
		if(!c[i]) for(int j = i * i ; j <= 50000 ; j += i) c[j] = 1;
	for(int i = l ; i <= r ; i++) 
		if(!c[i] && calc(i) > calc(res)) res = i;
	cout << ((res) ? res : -1);
	return 0;
}

