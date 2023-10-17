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
	freopen("SEQUENCE.inp" , "r" , stdin);
	freopen("SEQUENCE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , a[N] ;
bool check(int k)
{
	for (int i = 1 ; i <= n ; i++ , k++)
	{
		int p = k , ok = 0;
		while(p)
		{
			if(p % 10 == a[i]) ok = 1;
			p /= 10;
		}
		if(!ok) return false;
	}
	return true;
}
int main()
{
	file();
  cin >> n;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
 if(n <= 1000)
   {
	 for (int i = 0 ; i <= 1000 ; i++) if(check(i))
     {
  	    cout << i ;
  	    break;
     }
   }
  else
  {
  	int p = 1;
  	for (int i = 1 ; i <= 6 ; i++) 
  	{
  		p *= 10;
  		if(p >= n) break;
	}
	cout << a[1] * p ;
  } 
 return 0;
}

