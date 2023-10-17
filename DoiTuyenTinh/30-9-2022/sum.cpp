#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , inf = 1e9 + 7;

void file() {
	freopen("sum.inp" , "r" , stdin);
	freopen("sum.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , tmp[15];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= N ; i++)
		for(int c = 1 ; c <= 9 ; c++) {
			tmp[c] = (tmp[c] * 10 + c) % n;
			if(!tmp[c]) {
				int x = 0;
				while(x < n) x = x * 10 + c , i--;
				cout << x / n;
				x = x % n;
				while(i) {
					x = x * 10 + c;
					cout << x / n;
					x = x % n;
					i--;
				}
				return 0;
		}
	}
	cout << -1;
	return 0;
}

