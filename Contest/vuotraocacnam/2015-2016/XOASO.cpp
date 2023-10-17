#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k;
string s;
void file()
{
	freopen("XOASO.inp","r",stdin);
	freopen("XOASO.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>s>>k;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<s[i+1]) 
		{
		  s.erase(i,1);
		  if(i>=1) i-=2;
		  else i--;
		  k--;	
		  if(k==0) break;
		}
	}
	for(int i=0;i<s.size()-k;i++) cout<<s[i];
	return 0;
}
