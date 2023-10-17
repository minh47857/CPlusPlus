
#define X first
#define Y second
#define pb push_back
#include <bits/stdc++.h>

using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX = 1e5 + 10,M=102;
const int inf=1e9;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}

int dp[M][MAX];
int a[MAX];
int D[MAX],F[MAX],S[MAX];
signed main() {
    freopen("Block.inp","r",stdin);freopen("Block.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,K;
    cin >> n>>K;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    for(int k=1;k<=K;k++){
        a[0]=inf;
        int top=0;
        F[0]=inf;
        for(int i=1;i<=n;i++){
            int now=dp[k-1][i-1];
            while(a[i]>a[D[top]])
            {
                minn(now,S[top]);
                top--;
            }
            D[++top]=i;S[top]=now;
            F[top]=min(F[top-1],now+a[i]);
            dp[k][i]=F[top];
        }
    }
    cout<<dp[K][n];
}
