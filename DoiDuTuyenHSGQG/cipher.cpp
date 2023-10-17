#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7;
ll t , a[N] , n;
string s;
void file()
{
	freopen("cipher.inp" , "r" , stdin);
	freopen("cipher.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin >> t;
   while (t--)
   {
   	cin >> s ;
   	n = s.size();
   	s = ' ' + s;
   	if ( n % 2 == 1 ) 
   	{
   		cout << "AMBIGUOUS" << '\n' ;
   		continue;
	}
	memset ( a , 0 , sizeof (a));
	a[2] = s[1] - 'A';
	a[n - 1] = s[n] - 'A';
	for (int i = 3; i <= n ; i += 2)
	{
		int num = s[i] - 'A';
		if (num >= a[i - 1] ) a[i + 1] = num - a[i - 1];
		else a[i + 1] = num + 26 - a[i - 1];
	}
	for (int i = n - 2 ; i >= 2 ; i -= 2)
	{
		int num = s[i] - 'A';
		if (num >= a[i + 1] ) a[i - 1] = num - a[i + 1];
		else a[i - 1] = num + 26 - a[i + 1];
	}
	for (int i = 1; i <= n; i++) cout << char(a[i] + 'A') ;
	cout << '\n';
   } 
   return 0;
}

