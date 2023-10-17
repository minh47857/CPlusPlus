
#define X first
#define Y second
#define pb push_back
#include <bits/stdc++.h>

using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX = 2e5 + 10;
const int inf=2e9;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
int F[2][2][MAX];
int S[2];
vector < ii > pr[MAX];
void dfs(int v,int trc){
    int sum=0,x;
    auto &dp=F[0];
    //if(1){
        for(ii u:pr[v])if(u.X!=trc)
            dfs(u.X,v);
        S[0]=S[1]=-inf;

        for(ii u:pr[v])if(u.X!=trc){
            x=max(dp[0][u.X],u.Y+dp[1][u.X]);
            sum+=x;
            maxx(S[1],F[1][0][u.X]+u.Y-x+S[0]);
            maxx(S[0],dp[0][u.X]+u.Y-x);
            //if(v==1)  cout<<u.X<<' '<<x<<' '<<dp[0][u.X]+u.Y<<' '<<S[0]<<'\n';
        }
        dp[0][v]=sum;
        dp[1][v]=sum+S[0];
        //if(v==1) cout<<S[0]<<'\n';

    //}
    //if(v!=1){
        S[0]=-inf;
        for(ii u:pr[v])if(u.X!=trc){
            x=max(dp[0][u.X],dp[1][u.X]+u.Y);
            //sum+=x;
            maxx(F[1][0][v],max(F[1][0][u.X],F[1][1][u.X]+u.Y)-x);
            maxx(S[1],dp[0][u.X]+u.Y-x+S[0]);
            maxx(S[0],F[1][0][u.X]+u.Y-x);
        }
        maxx(F[1][0][v],S[1]);
        F[1][0][v]+=sum;
        F[1][1][v]=sum+S[0];
        maxx(F[1][0][v],dp[0][v]);
    //}
        return;
        cout<<v<<'\n';
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)cout<<i<<' '<<j<<' '<<F[i][j][v]<<'\n';
}

signed main() {
    freopen("beads.inp","r",stdin);freopen("beads.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int Z=0;
    for(int i=1,x,y,c;i<n;i++){
        cin>>x>>y>>c;
        pr[x].pb(ii(y,c));
        pr[y].pb(ii(x,c));
        Z+=c;
    }
    //cout<<Z<<'\n';
    dfs(1,0);
    cout<<F[1][0][1];
}
