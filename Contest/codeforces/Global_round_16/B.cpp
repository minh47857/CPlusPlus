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
int n , t , ans , dem0 , dem1;
string str;
int main()
{
	file();
 cin >> t;
 while(t--)
 {
 	cin >> str;
 	n = str.size();
 	str = ' ' + str;
 	ans = 2;
 	dem0 = dem1 = 0;
 	for(int i = 1 ; i <= n ; i++)
 	{
 		if(str[i] == '0') 
		 {
		 	dem0++;
 	        while(str[i + 1] == '0' && i < n) i++;
 	     }
 	     else
 	     {
 	     	dem1++;
 	     	 while(str[i + 1] == '1' && i < n) i++;
		 }
    }
  //  cout << dem1 << ' ' << dem0 << endl;
    if(dem1 == 1 && dem0 == 0) ans = 0;
    else if(dem0 == 1) ans = 1;
    cout << ans << '\n';
 }
}

