#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
    freopen("FROGS.inp" , "r" , stdin);
	freopen("FROGS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , w[N] , p[N][25];
deque<int> dq;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	a[n + 1] = inf;
	for(int i = 1 ; i <= n ; i++)
		cin >> w[i];
	dq.pb(n + 1);
	for(int i = n ; i >= 1 ; i--) {
		while(dq.size() && a[i] >= a[dq.back()]) 
			dq.pop_back();
		p[i][0] = dq.back();
		dq.pb(i);
	}
	p[n + 1][0] = n + 1;
	for(int j = 1 ; j <= 20 ; j++) 
		for(int i = 1 ; i <= n + 1 ; i++) 
			if(i + (1 << j) - 1 <= n + 1) 
				p[i][j] = p[p[i][j - 1]][j - 1];
			else p[i][j] = n + 1;
	for(int i = 1 ; i <= n ; i++) {
		int k = i;
		for(int j = 20 ; j >= 0 ; j--) 
			if((1 << j) <= w[i]) 
				w[i] -= (1 << j), k = p[k][j];
	//	cout << i << ' ' << k << ' ';
		cout << ((a[k] == inf) ? -1 : a[k])	<< ' ';	
	}
}


