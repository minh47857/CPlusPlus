#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
int x , s = 0 ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
 for (int i = 1 ; i <= 6 ; i++)
 {
 	cin >> x ;
 	s += x;
 }
 if (s >= 373) cout << "YES";
 else cout << "NO";
 return 0;
}

