#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("JOURNEY.inp" , "r" , stdin);
	freopen("JOURNEY.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int x , y , U , D , L , R , k;
string str;
vector<char> ans;

int main() {
	file();
	cin >> x >> y;
	cin >> str;
	for(int i = 0 ; i < str.size() ; i++) {
		if(str[i] == 'U') U++;
		if(str[i] == 'D') D++;
		if(str[i] == 'L') L++;
		if(str[i] == 'R') R++;
	}
	k = str.size() - U - D - L - R;
	x = x - R + L;
	y = y - U + D;
	k = k- abs(x) - abs(y);
	if(k < 0 || k % 2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for(int i = 1 ; i <= abs(x) ; i++) {
		if(x < 0) ans.pb('L') ; 
		else ans.pb('R'); 
	}
	for(int i = 1 ; i <= abs(y) ; i++) {
		if(y < 0) ans.pb('D') ;
		else ans.pb('U');
	}
	for(int i = 1 ; i <= k / 2 ; i++)
		ans.pb('U') , ans.pb('D');
	sort(ans.begin() , ans.end() , greater<char>());
	for(int i = 0 ; i < str.size() ; i++) {
		if(str[i] != '?') cout << str[i];
		else {
			cout << ans.back();
			ans.pop_back();
		}
	}
	return 0;
}


