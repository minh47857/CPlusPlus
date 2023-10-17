#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
ll x,k;
void file()
{
	freopen("DAYSO.inp","r",stdin);
	freopen("DAYSO.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>k;
	for(int i=1;i<=k;i++)
    {
    	cin>>x;
    	cout<<((x+1)%10*(x+1)%10)%10<<endl;
	}
}
