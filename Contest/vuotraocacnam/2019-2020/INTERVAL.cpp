#include<bits/stdc++.h>
using namespace std;
const long long N=1000005;
long long a,b;
void file()
{
	freopen("INTERVAL.inp","r",stdin);
	freopen("INTERVAL.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

long long tinh(long long n)
{
    long long res,p;
   if (n<10) return n;
   res=9 + n/10;
   p=n;
   while (p>=10) p=p/10;
   if (p>n%10)  res--;
   return res;
}
int main()
{
//	file();
	cin>>a>>b;
	cout<<tinh(b)-tinh(a-1);
	
}
