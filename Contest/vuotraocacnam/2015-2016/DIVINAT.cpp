#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,res;
void file()
{
	freopen("DIVINAT.inp","r",stdin);
	freopen("DIVINAT.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>n;
	res=n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			while(n%i==0) n/=i;
			res-=res/i;
		}
	}
	if(n!=1) res-=res/n;
	cout<<res;
}
