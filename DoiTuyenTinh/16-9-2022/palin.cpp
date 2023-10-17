#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("palin.inp" , "r" , stdin);
	freopen("palin.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string str;

int main() {
	file();
	while(cin >> str) {
		int n = str.size() , res = 0;
		for(int i = 0 ; i < n / 2 ; i++) 
			if(str[i] != str[n - i - 1]) res++;
		cout << ((res <= 2) ? "YES\n" : "NO\n");
	}
}
