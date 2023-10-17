#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("encode.inp" , "r" , stdin);
	freopen("encode.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

char a[15];
int s , p;

int main() {
	file();
	for(int i = 1 ; i <= 10 ; i++) cin >> a[i];
	for(int i = 1 ; i <= 10 ; i++) {
		if(a[i] == '?') p = i;
		else s += i * (a[i] - '0');
	}
	for(int i = 0 ; i <= 9 ; i++)
		if((s + p * i ) % 11 == 0) {
			p = i;
			break;
		}
	cout << p;
	return 0;
}

