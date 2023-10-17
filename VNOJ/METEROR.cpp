#include<bits/stdc++.h>
using namespace std;
const long long N=10000005;
long long q,n,r,x,y,z,vx,vy,vz,d[N],t[N],Max=-1,TiMe[N];
int main()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++) 
	{
		cin>>x>>y>>z>>vx>>vy>>vz;
	long long 	a=vx*vx+vy*vy+vz*vz;
	  long long  c=x*x+y*y+z*z-r*r;
	long long    b=2*(x*vx+y*vy+z*vz);
	  long long   denta=b*b-4*a*c;
	 // cout<<a<<" "<<b<<" "<<c<<endl;
	    if(denta<0) continue;
	    long double x1 = (-b - sqrt((long double) denta)) / 2.0 / a;
        long double x2 = (-b + sqrt((long double) denta)) / 2.0 / a;
        if(x2<0) continue;
        if(x1<0) x1=0;	 
        long long x3=x1,x4=x2;
        if(x3==x1) d[x3]++;
        else  	d[x3+1]++;
        d[x4+1]--;   
       // cout<<x1<<" "<<x2<<endl;
       // cout<<x3<<" "<<x4<<endl;
	} 
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>> t[i];
		Max=max(t[i],Max);
	 } 
	 TiMe[0]=d[0];
	// for(int i=0;i<=Max;i++) cout<<d[i]<<" ";
	 for(int i=1;i<=Max;i++) TiMe[i]=TiMe[i-1]+d[i];
	 for(int i=1;i<=q;i++) cout<<TiMe[t[i]]<<endl;
	
}
