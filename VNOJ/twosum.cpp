#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 5001;
int s[N] , a[N] , ans = 0 , n , sum , d , c , kq , g;
int main()
{
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  cin >> n ;
  s[0] = 0;
  for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
  for (int i = 1 ; i <= n ; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1 ; i <= n ; i++)
  for (int j = i ; j >= 2 ; j--)
  {
  	 sum = s[j - 1] - s[i] + s[j - 1];
     d = 0 , c = j - 2 , kq = -1 , g;
  	while (d <= c)
  	{
  	     g = (d + c) / 2;
  		if (s[g] == sum) 
  		{
  			kq = g;
  			break;
		}
		if (s[g] > sum) c = g - 1;
		else d = g + 1;
	}
	if (kq != -1) ans = max(ans , i - kq);
  }
  cout << ans;
  return 0;
}

