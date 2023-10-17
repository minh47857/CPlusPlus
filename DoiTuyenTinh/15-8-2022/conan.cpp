#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("conan.inp" , "r" , stdin);
	freopen("conan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s1 , s2;
int d1[30] , d2[30] , ans;

int main() {
	file();
	cin >> s1 >> s2;
	for(int i = 0 ; i < s1.size() ; i++) d1[s1[i] - 'a']++;
	for(int i = 0 ; i < s2.size() ; i++) d2[s2[i] - 'a']++;
	for(int i = 0 ; i <= 25 ; i++) ans += min(d1[i] , d2[i]);
	cout << ans;
	return 0;
}

