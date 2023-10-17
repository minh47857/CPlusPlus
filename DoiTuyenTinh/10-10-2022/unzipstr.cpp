#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pi pair<int , int>
#define pb push_back

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("unzipstr.inp" , "r" , stdin);
	freopen("unzipstr.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string s;

int main() {
	file();
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++) {
		if(s[i] < '0' || s[i] > '9') cout << s[i];
		else {
			int x = 0;
			while(i < s.size() && s[i] <= '9' && s[i] >= '0') 
				x = x * 10 + s[i] - '0' , i++;
			while(x--) cout << s[i];
		}
	}
	return 0;
}

