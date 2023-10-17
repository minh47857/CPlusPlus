#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=205,MOD=100000;
char op[] = {'(','[','{'};
char clo[] = {')',']','}'};
long long n,dp[N][N];
string s;
void file()
{
	freopen("DAYNGOAC.inp","r",stdin);
	freopen("DAYNGOAC.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int check(char x,char y)
{
	if(x=='?'&&y=='?') return 3;
	if(x=='?')
	{
		if(y==clo[0]||y==clo[1]||y==clo[2]) return 1;
	}
	if(y=='?')
	{
		if(x==op[0]||x==op[1]||x==op[2]) return 1;
	}
	for(int i=0;i<3;i++)
	if(x==op[i]&&y==clo[i]) return 1;
	return 0;
	
}
ll tinh(int l,int r)
{
	if(l>r) return 1;
	ll &res=dp[l][r];
	if( res > -1) return res;
	res=0;
	for(int i=l+1;i<=r;i+=2)
	{
		res=res+tinh(l+1,i-1)*tinh(i+1,r)*check(s[l],s[i]);
	//	cout<<check(s[l],s[i])<<" "<<s[l]<<" "<<s[i]<<endl;
		res %=MOD;
	}
	return  res;
}
int main()
{
	file();
	cin>>n;
    cin>>s;
    s=' '+s;
    memset(dp,-1,sizeof dp);
    cout<<tinh(1,n);
    return 0;
}

