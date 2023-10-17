#include<bits/stdc++.h>
#define int long long
#define task "block"
using namespace std;
using ii=pair<int,int>;

const int mn=1e3+11,inf=0x3f3f3f3f3f3f3f3f;
const int mk=111;

int n,k;
int a[mn];
int dp[mn][mk];
int mval[mn][mn];

bool ckmin(int& a,int b){
    return a>b ? a=b,1 : 0;
}

int32_t main()
{
    #ifdef _TPR_
        freopen("t.inp","r",stdin);
        freopen("t.out","w",stdout);
    #else
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    #endif // _TPR_

    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        mval[i][i]=a[i];
        for(int j=i+1;j<=n;j++)
            mval[i][j]=max(mval[i][j-1],a[j]);
    }

    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            for(int k=0;k<i;k++)
                ckmin(dp[i][j],dp[k][j-1]+mval[k+1][i]);
        }
    }

    cout<<dp[n][k];
}

