#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int ans , d[30];
int main() {
	//freopen("xaudx.inp" , "r" , stdin);
	//freopen("xaudx.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++) d[s[i] - 'a']++;
	for(int i = 0 ; i <= 25 ; i++) ans += d[i] % 2;
	cout << max(ans - 1 , 0);
	return 0;
}
