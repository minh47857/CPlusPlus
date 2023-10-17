#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
ll a,b,c;
string s;
void file()
{
	freopen("TRIK.inp","r",stdin);
	freopen("TRIK.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	a=1,b=0,c=0;
	cin>>s;
	for(int i=0;i<s.size();i++) 
	{
		if(s[i]=='A') swap(a,b);
		if(s[i]=='B') swap(c,b);
		if(s[i]=='C') swap(a,c);	
	}
	if(a==1) cout<<1;
	if(b==1) cout<<2;
	if(c==1) cout<<3;
	
}
