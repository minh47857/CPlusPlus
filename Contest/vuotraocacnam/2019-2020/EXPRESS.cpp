#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long s=0,a[N],n,k;
void file()
{
	freopen("EXPRESS.inp","r",stdin);
	freopen("EXPRESS.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+2,a+n+1,greater<int>());
	s=a[1];
	for(int i=2;i<=n;i++)
	{
		if(i<=k+1) s+=a[i];
		else s-=a[i];
	}
	cout<<s;
}
