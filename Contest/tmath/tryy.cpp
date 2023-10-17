#include<bits/stdc++.h>
using namespace std;
long long i,j,m,k,n,a[1000001],s[1000001];
int main()
{
   // freopen("qarr.inp","r",stdin);
   // freopen("qarr.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    for(k=1;k<=m;k++)
    {
        cin>>i>>j;
        if(i<=j)
        {
            a[i]++;
            a[j+1]--;
        }
    }
    for(i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        cout<<s[i]<<endl;
    }
    return 0;
}
