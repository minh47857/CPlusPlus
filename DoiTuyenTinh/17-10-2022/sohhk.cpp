#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , M = 20000000 , inf = 1e9 + 7;

void file() {
	freopen("sohhk.inp" , "r" , stdin);
	freopen("sohhk.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k , x , y , sum;

int main() {
	file();
	cin >> k;
	while(k){
		x++;
		y = x;
		sum = 0;
		while(y) sum += y % 10 , y /= 10;
		if(sum == 10) k--;
	}
	cout << x;
	return 0;
}

