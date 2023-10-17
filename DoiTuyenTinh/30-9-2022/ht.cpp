#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("ht.inp" , "r" , stdin);
	freopen("ht.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
map<string , int> d;

int main() {
	file();
	cin >> s;
	for(int i = 0 ; i < s.size() - 2 ; i++) 
		d[s.substr(i , 3)]++;
	cout << d["TTT"] << ' ' << d["TTH"] << ' ' << d["THT"] << ' ' << d["THH"] << ' '
		 << d["HTT"] << ' ' << d["HTH"] << ' ' << d["HHT"] << ' ' << d["HHH"];
	return 0;
}

