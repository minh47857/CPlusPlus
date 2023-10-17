#include<bits/stdc++.h>
#define ll long long
#define itm LONG_LONG_MAX
using namespace std;
const int mmax = 2*(1e3)+5;
ll res=itm,n,m,k,a[mmax],dp[mmax][mmax];
int main()
{

    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    
    for(int i=0;i<=n;++i)
          for(int j=0;j<=n;++j)
                dp[i][j]=itm;
        
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=i;++j)
                {
                    if(i-j > m) continue;
                    if(j==0) dp[i][j]=dp[i-1][j];
                    else
                        {
                            if(j%k==0)
                                
                                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);
                                
                            else
                                   dp[i][j]=min(dp[i-1][j-1]+a[i],dp[i-1][j]);
                                
                        }
                }
        }
    for(int i=0;i<=n;++i)
        {
            if(n-i>m) continue;
            res=min(res,dp[n][i]);
        }
    cout<<res;
    return 0;
}
