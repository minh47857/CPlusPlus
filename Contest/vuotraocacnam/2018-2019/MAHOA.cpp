#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string a,s1[N],s2[N];
int m=0,n=0,d1[N];
map <string,int> d;
void file()
{
	freopen("MAHOA.inp","r",stdin);
	freopen("MAHOA.inp","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool check(int k)
{
	map<string ,int>  d2;
		for(int j=0;j<n;j++)
		{
		  d2[s1[j+k]]++;
		  if(d2[s1[j+k]]!=d1[j+1]) return false;
		}
		return true;
}
int main()
{
	file();
	while(cin>>a)
	{
		if(a=="$") break;
		m++;
		s1[m]=a;
	}
	while(cin>>a)
	{
		if(a=="$") break;
		n++;
		s2[n]=a;
		d[s2[n]]++;
		d1[n]=d[s2[n]];
	}
	
	for(int i=1;i<=m;i++)
	{
		if(check(i))
		{
			cout<<i;
			return 0;
		}
	}
}
