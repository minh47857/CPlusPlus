#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const long long N=1000001;
long long t,n,m;
pair<long long,long long> a[N],b[N];
long long tknp(long long d,long long c)
{
	long long g,res;
	while(d<=c)
    {
    	g=(d+c)/2;
    	long long kq1=0,kq2=0;
    	for(int i=1;i<=n;i++)	
		{
			kq1=kq1+(g-a[i].fi)/a[i].se+1;
			//cout<<kq1<<" ";
		}
		for(int i=1;i<=m;i++) 
		{
			kq2=kq2+(t-g-b[i].fi)/b[i].se+1;
			//cout<<kq2<<" ;
		  }  
	//	cout<<g<<" "<<kq1<<" "<<kq2<<endl;
		if(kq1==kq2) 
		{
			res=g;
			break;
		 } 
		 if(kq1>kq2) c=g-1;
		 if(kq1<kq2) d=g+1;
	}
	return res;
}
int main()
{
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i].fi>>b[i].se;
	cout<<tknp(1,t);
	
}
