#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("bdxau.inp" , "r" , stdin);
	freopen("bdxau.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;

int main() {
	file();
	cin >> s;
	if(s == "1" || s.substr(0 , 2) == "10" || s.substr(s.size() - 2 , 2) == "01") {
		cout << "Khong the bien doi duoc";
		return 0;	
	}
	if(s.substr(s.size()-2,2)=="11") {
		s.replace(s.size() - 2 , 2 , "00");
		cout << s << endl;
	}
	for(int i = 0; i <= s.size(); i++) 
		if(s[i] == '1') {
			s.replace(i , 2 , "00");
			cout << s <<endl;	
		}
}

