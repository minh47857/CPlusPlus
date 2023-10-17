#include <bits/stdc++.h>

using namespace std;

int const maxN=1e5;
int const maxK=1e2;
int const inf=0x3f3f3f3f;

int N,K;
int a[maxN+3];
int f[2][maxN+3];

int Node[maxN<<2],Lazy[maxN<<2];
struct S1{
#define lef ((i)<<1)
#define rig ((i)<<1|1)
    void Push(int i){
        Node[lef]+=Lazy[i];
        Node[rig]+=Lazy[i];
        Lazy[lef]+=Lazy[i];
        Lazy[rig]+=Lazy[i];
        Lazy[i]=0;
        return ;
    }
    void Upd(int i,int l,int r,int p,int x){
        if(l==r){
            Node[i]=x;
            return ;
        }
        Push(i);
        int m=(l+r)>>1;
        if(p<=m){
            Upd(lef,l,m,p,x);
        }
        else{
            Upd(rig,m+1,r,p,x);
        }
        Node[i]=min(Node[lef],Node[rig]);
        return ;
    }
    void Upd(int i,int l,int r,int u,int v,int x){
        if(r<u||v<l||v<u){
            return ;
        }
        if(u<=l&&r<=v){
            Node[i]+=x;
            Lazy[i]+=x;
            return ;
        }
        Push(i);
        int m=(l+r)>>1;
        Upd(lef,l,m,u,v,x);
        Upd(rig,m+1,r,u,v,x);
        Node[i]=min(Node[lef],Node[rig]);
        return ;
    }
    int Get(int i,int l,int r,int u,int v){
        if(v<l||r<u||v<u){
            return inf;
        }
        if(u<=l&&r<=v){
            return Node[i];
        }
        Push(i);
        int m=(l+r)>>1;
        return min(Get(lef,l,m,u,v),Get(rig,m+1,r,u,v));
    }
}IT;

int Stack[maxN+3],S_top;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("block.inp","r",stdin);
    freopen("block.out","w",stdout);
    cin>>N>>K;
    for(int i=1;i<=N;++i){
        cin>>a[i];
    }
    int cur=0;
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int k=1;k<=K;++k){
        S_top=0;
        for(int i=1;i<=N;++i){
            IT.Upd(1,1,N,i,f[cur][i-1]+a[i]);
            //cout<<i<<' '<<f[cur][i-1]+a[i]<<'\n';
            while(S_top&&a[i]>=a[Stack[S_top]]){
                IT.Upd(1,1,N,Stack[S_top-1]+1,Stack[S_top],a[i]-a[Stack[S_top]]);
                //cout<<Stack[S_top-1]+1<<' '<<Stack[S_top]<<' '<<a[i]-a[Stack[S_top]]<<'\n';
                --S_top;
            }
            Stack[++S_top]=i;
            f[cur^1][i]=IT.Get(1,1,N,1,i);
            //cout<<i<<'='<<f[cur^1][i]<<'\n';
        }
        f[cur][0]=inf;
        cur^=1;
    }
    cout<<f[cur][N];
    return 0;
}
