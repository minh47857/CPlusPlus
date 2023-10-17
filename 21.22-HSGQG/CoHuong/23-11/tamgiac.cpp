#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("tamgiac.inp" , "r" , stdin);
	freopen("tamgiac.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int a[N] , n;
namespace sub12
{
	int ans = 0 , d[5];
	void solve()
	{
		for(int i = 3 ; i <= n ; i++)
		{
			d[1] = a[i] , d[2] = a[i - 1] , d[3] = a[i - 2];
			sort(d + 1 , d + 4);
			if(d[1] + d[2] > d[3]) ans = max(ans , 3);
		  for(int j = i - 3 ; j >= 1 ; j--)
		  {
		  	if(a[j] > d[3]) d[3] = a[j];     
		     else  if(a[j] < d[1])
		      {
		      	d[2] = d[1];
		      	d[1] = a[j];
			  }
			  else if(a[j] < d[2]) d[2] = a[j];
			  if(d[1] + d[2] > d[3]) ans = max(ans , i - j + 1);
		  }
	    }
	    cout << ans;
	}
}

namespace sub3
{
	int ans = 0 , j;
	multiset<int> s;
	void solve()
	{
		j = 1;
		s.insert(a[1]) , s.insert(a[2]) , s.insert(a[3]);
		if(*s.begin() + *(++s.begin()) > *s.rbegin()) ans = max(ans , 3);
		for(int i = 4 ; i <= n ; i++)
		{
			s.insert(a[i]);
			while(i - j > 2 && *s.begin() + *(++s.begin()) <= *s.rbegin()) 
			{
			//	cout << *s.begin()  << ' ' <<  *(++s.begin()) << ' ' << *s.rbegin() << '\n';
				s.erase(s.find(a[j]));
				j++;
			}
			if(*s.begin() + *(++s.begin()) > *s.rbegin()) ans = max(ans , i - j + 1);
		}
		cout << ans;
	}
}

int main()
{
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++)  cin >> a[i];
  //if(n <= 1000) sub12::solve();
    sub3::solve();
}

