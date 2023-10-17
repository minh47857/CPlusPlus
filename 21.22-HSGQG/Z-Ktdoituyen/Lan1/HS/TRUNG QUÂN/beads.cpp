#include<bits/stdc++.h>
#define int long long
#define task "beads"
using namespace std;
using ii=pair<int,int>;

const int mn=2e5+11;

int n;
int dp[mn][3];
//dp[u][0]: orthodox root style
//dp[u][1]: parent is child
//dp[u][2]: child is parent
vector<ii>adj[mn];

int res=0;

struct holder{
    int t1,t2,t3;
    int i1,i2,i3;
    holder():t1(-1),t2(-1),t3(-1),
            i1(-1),i2(-1),i3(-1){}

    void insert(int x,int idx){
        if(x>t1)
            t3=t2,t2=t1,
            i3=i2,i2=i1,
            t1=x,i1=idx;
        else if(x>t2)
            t3=t2,t2=x,
            i3=i2,i2=idx;
        else if(x>t3)
            t3=x,i3=idx;
    }
};


void dfs(int u,int pre,int pre_height){
    holder st;
    dp[u][0]=0;
    for(const ii& k:adj[u]){
        int v=k.first,w=k.second;
        if(v!=pre){
            dfs(v,u,w);
            st.insert(dp[v][0]+w,v);
        }
    }

    if(st.t1!=-1 && st.t2!=-1)
        dp[u][0]=st.t1+st.t2;

    if(st.i1!=-1){
        dp[u][1]=st.t1;
        if(st.i2!=-1)for(const ii& k:adj[u]){
            int v=k.first,w=k.second;
            if(v==pre)continue;
            int exc = (v!=st.i1 ? st.t1 : st.t2);
            dp[u][1]=max(dp[u][1],max(0LL,dp[v][1])+exc+w);
        }
    }

    if(st.i3!=-1)for(const ii& k:adj[u]){
        int v=k.first,w=k.second;
        if(v==pre)continue;
        int accl=0,cnt=0;
        if(st.i1!=v)cnt++,accl+=st.t1;
        if(st.i2!=v)cnt++,accl+=st.t2;
        if(st.i3!=v && cnt<2)accl+=st.t3;
        dp[u][2]=max(dp[u][2],dp[v][1]+w+accl);
    }

    res=max(res,dp[u][0]);
    res=max(res,dp[u][2]);
    if(pre!=-1)
        res=max(res,dp[u][1]+pre_height);
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

    cin>>n;

    for(int i=2,u,v,w;i<=n;i++){
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    memset(dp,0xc0,sizeof(dp));
    dfs(1,-1,-1);
    cout<<res;
}
