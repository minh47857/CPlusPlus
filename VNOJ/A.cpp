//https://codeforces.com/contest/1556/problem/A
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll q  , x , y;
int main()
{
// 	file();
  cin >> q;
  while (q--)
  {
  	cin >> x >> y;
  	if (abs(x - y) % 2) cout << -1 << '\n';
  	else 
  	{
  		if(x == y )
		  {
		  	if(x <= 0) cout << 0 << '\n';
		  	else cout << 1 << '\n';
		  }
  		else cout << 2 << '\n';
	}
  }
  return 0;
cout << 4;
return 0;

}

