#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define lb long double
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
lb x , y;
int main()
{
  cin >> x >> y;
  lb b = x + y;
  lb c = y * y - x * x;
  lb denta = b * b - c;
  lb n1 = b - sqrt(denta);
  lb n2 = y - n1;
  lb n3 = n1 + x;
  cout << fixed << setprecision(9)  << min(n1 , n2) << ' ' << max(n1 , n2) <<' ' << n3;
  return 0;
}

