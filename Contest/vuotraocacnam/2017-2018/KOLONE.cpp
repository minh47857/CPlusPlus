#include<bits/stdc++.h>
using namespace std;
string s1,s2,s;
int a,b,d[1000001],t;
int main()
{
	freopen("KOLONE.inp","r",stdin);
	freopen("KOLONE.out","w",stdout);
	cin>>a>>b;
	cin>>s1>>s2>>t;
	reverse(s1.begin(),s1.end());
	s=s1+s2;
	for(int i=0;i<a+b;i++) 
	{
		if(i<a) d[i]=1;
		else d[i]=2; 
	}
	for(int j=1;j<=t;j++)
	{
		for(int i=0;i<a+b;i++)
		{
			if((d[i]-d[i+1])==-1) 
			{
				swap(d[i],d[i+1]);
				swap(s[i],s[i+1]);
				i++;
			}
		}
	}
	cout<<s;
}
