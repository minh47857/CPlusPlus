#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long a,b,k,x,y;
long long nhan(long long m,long long n)
{
	if(n==0) return 0;
	 if(n%2==0) return (nhan(m,n/2)%b+nhan(m,n/2)%b)%b;
	return (m%b+nhan(m,n/2)%b+nhan(m,n/2)%b)%b;
}
long long sqr(long long k)
{
	return nhan(k,k);
}
long long mu(long long m,long long n)
{
    if(n==0) return 1;
    if(n%2==0) return sqr(mu(m,n/2));
    return nhan(m%b,sqr(mu(m,n/2)));
}


int main()
{
	cin >>a>>b>>k;
	x= mu(10,k-1) ;
	y= nhan(a,x);
	cout<<(y*10)/b;
	return 0;
}
