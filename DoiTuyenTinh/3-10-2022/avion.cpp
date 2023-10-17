#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("avion.inp" , "r" , stdin);
	freopen("avion.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s[10];
bool ck = false;

int main() {
	file();
	for(int i = 1 ; i <= 5 ; i++) cin >> s[i];
	for(int i = 1 ; i <= 5 ; i++) {
		bool ok = false;
		for(int j = 0 ; j < s[i].size() - 2 ; j++) ok |= (s[i].substr(j , 3) == "FBI");
		if(ok) cout << i << ' ' , ck = true;
	}
	if(!ck) cout << "HE GOT AWAY!";
	return 0; 
}

