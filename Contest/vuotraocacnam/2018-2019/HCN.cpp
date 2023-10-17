#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
pair<int,int>a,b,c,d;
int x1,x2,x3;
void file()
{
	freopen("HCN.inp","r",stdin);
	freopen("HCN.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>a.fi>>a.se>>b.fi>>b.se>>c.fi>>c.se;
	x1=(a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
	x2=(c.fi-b.fi)*(c.fi-b.fi)+(c.se-b.se)*(c.se-b.se);
	x3=(a.fi-c.fi)*(a.fi-c.fi)+(a.se-c.se)*(a.se-c.se);
	if(x1>x2&&x1>x3) 	
	{
		d.fi=b.fi+a.fi-c.fi;
		d.se=b.se+a.se-c.se;
	}
	if(x2>x3&&x2>x1)   
	  {
		d.fi=b.fi+c.fi-a.fi;
		d.se=b.se+c.se-a.se;
	  }
	if(x3>x2&&x3>x1)  
	   {
		d.fi=c.fi+a.fi-b.fi;
		d.se=c.se+a.se-b.se;
	   }	
	   cout<<d.fi<<" "<<d.se;
	   return 0;
}
