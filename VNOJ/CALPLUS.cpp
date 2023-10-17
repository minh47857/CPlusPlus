#include<bits/stdc++.h>
using namespace std;
const int nmax=3005;
const long long oo=1e12+7;
int a[nmax],n,R[nmax][nmax];
long long f[nmax][nmax],s[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin>>n;
    memset(f,0x3f,sizeof f);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        f[i][i]=0;
        R[i][i]=i;
    }
    for (int i=n-1;i>=1;i--)
        for (int j=i+1;j<=n;j++)
            for (int k=R[i][j-1];k<=R[i+1][j];k++)
            {
                long long tmp=f[i][k]+f[k+1][j]+(s[j]-s[i-1])*(s[j]-s[i-1]);
                if (tmp<f[i][j])
                {
                    f[i][j]=tmp;
                    R[i][j]=k;
                }
            }
    cout<<f[1][n]<<'\n';
}
   