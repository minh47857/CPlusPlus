#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
string f[N];
map<string , int> d;

string sum(string a) {
	string res = "";
	int tmp , nho;
	reverse(a.begin() , a.end());
	for(int i = 0 ; i < a.size() ; i++) {
		tmp = (a[i] - '0') * 2 + nho;
		res += tmp % 10 + '0';
		nho = tmp / 10;
	}
	res += nho + '0';
	sort(res.begin() , res.end());
	while(res[0] == '0') res.erase(0 , 1);
	return res;
}

int main() {	
	cin >> n;
	f[1] = "1";
	for(int i = 2 ; i <= 32 ; i++) 
		f[i] = sum(f[i - 1]) , cout << f[i] << '\n';
	if(n <= 32) 
	return 0;
}

