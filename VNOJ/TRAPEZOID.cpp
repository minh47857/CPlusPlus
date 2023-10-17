#include<bits/stdc++.h>
using namespace std;
const int  N=5005;
int t;
long long tinh(long long x)
{
	return ((x-1)*x)/2;
}
int main()
{
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		long long n,a[N],sum=0,s1,s2,dem,tong=0;
		cin>>n;
		for(int j=1;j<=n;j++) cin>>a[j];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			dem=1;
			s2=i-1;
			while(a[i]==a[i+1])
			{
				i++;
				dem++;
				if(i==n) break;
			}
			
			if(dem>=2)
			{
			  sum=sum+((dem-1)*(dem-2)*(dem-3)*dem)/24;
			  s1=tinh(dem);
			  s2=tinh(n-(i-s2));
			  sum=sum+s1*(s2-tong);
			  tong+=s1;
			  cout<<sum<<" ";
			  sum=sum+((dem-2)*(dem-1)*dem)/6*(n-(i-s2));
			  cout<<sum<<" "<<s1<<" "<<s2<<endl;
			}
			
		}
	//	cout<<sum<<endl;
	}
}
