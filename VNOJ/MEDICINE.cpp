#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 31 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
	string s;
	int dem = 0 , d[N];
int main()
{
   file();
   cin >> s;
   for (int i = 0 ; i < s.size() ; i++) if (!d[s[i] - 'a']) dem++ , d[s[i] - 'a'] = 1;
   cout << dem;
   return 0;
}

