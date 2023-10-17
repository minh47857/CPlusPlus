#include<bits/stdc++.h>
using namespace std;
int a[100],w,h,n;
int main()
{
	freopen("SIBICE.inp","r",stdin);
	freopen("SIBICE.out","w",stdout);
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++) 	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]*a[i]<=(w*w+h*h)) cout<<"DA"<<endl;
		else cout<<"NE"<<endl;
	}
	return 0;
}
