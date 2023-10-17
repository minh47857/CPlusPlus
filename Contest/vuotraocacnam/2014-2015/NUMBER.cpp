#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=1000000;
ll xm,d,k,uoc;
string kq,res;
void file()
{
	freopen("NUMBER.inp","r",stdin);
	freopen("NUMBER.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void chia(int m)
{
   long long 	dem=m,s=0,nho=0;
    
   while(dem!=0)
   {
   	if(s==0)
   	{
   		while(s<xm)
   		{
   			s=s*10+9;
   	 	dem--;
		   }
   		
	   }
   	else {
   		s=s*10+9;
   	 	dem--;
	     }	
	 int x=s/xm;
	 res+=(x+'0');
     s=s%xm;
   }
   for(int i=res.size()-1;i>=0;i--)
   {
   	 kq+=((((res[i]-'0')*d)+nho)%10+'0');
   	
   	 nho=(((res[i]-'0')*d)+nho)/10;
   }
   if(nho!=0) kq+=(nho +'0');
   reverse(kq.begin(),kq.end());
}
string solve()
{
	ll sum=0;
	for(int i=1;i<=N;i++)
	{
		sum=(sum*10+9)%xm;
		if(sum==0) 
		{
		  chia(i);
		  
		  return kq;	
		}
	}
	return "-1";
}
int main()
{
	file();
	cin>>d>>k;
	if(d<k) 
	{
		cout<<-1;
		return 0;
	}
	uoc=__gcd(10*k-1,d);
	xm=(10*k-1)/uoc;
	d/=uoc;
	cout<<solve();
	return 0;
}
