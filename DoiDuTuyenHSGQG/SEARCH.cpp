#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e15;
ll n , q , cnt , sl , Next[N][30] , num[N][30];
string str;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin >> n >> q;
  memset ( Next , - 1 , sizeof (Next));
  memset ( num , 0 , sizeof (num)); 
  cnt = 0;
  while (n--)
  {
  	cin >> str;
  	sl = 0 ;
  	for (int i = 0 ; i < str.size() ; i++)
  	{
  		if (Next[sl][str[i] - 'a'] == -1) cnt ++ , Next[sl][str[i] - 'a'] = cnt ;
  		num[sl][str[i] - 'a']++;
  	    sl = Next[sl][str[i] - 'a'];
	}
  }
 // cout << cnt << endl;
  //for (int i = 1 ; i <= )
  while(q --)
  {
  	cin >> str;
  	sl = 0;
  	bool check = true;
  		for (int i = 0 ; i < str.size() ; i++) 
		  {
		  	if(Next[sl][str[i] - 'a'] == -1) 
		  	{
		  		cout << 0 << '\n';
		  		check = false;
		  		break ;
			}
		  if (i != str.size() - 1)	sl = Next[sl][str[i] - 'a'];
		  }
		 if (check) cout << num[sl][str[str.size() - 1] - 'a'] << '\n';
  		
  }
   return 0;
}

