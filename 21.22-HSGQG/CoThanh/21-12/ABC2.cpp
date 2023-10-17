#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("ABC2.inp" , "r" , stdin);
	freopen("ABC2.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll demA , demB , demC , demA2 , demB2 , demC2;
string str;

int main() {
	file();
	cin >> str;
	for(int i = 0 ; i < str.size() ; i++) {
		if(str[i] == 'a') demA++ , demA2 += demC2;
		if(str[i] == 'b') demB += demA , demB2 += demC;
		if(str[i] == 'c') demC += demB , demC2 += demB2;
	}
	cout << demA2;
	return 0;
}


