#include<bits/stdc++.h>
#define int long long
using namespace std;
using ii=pair<int,int>;

template<typename t>
bool ckmin(t& target,const t& source){
    return target>source ? target=source,1 : 0;
}
template<typename t>
bool ckmax(t& target,const t& source){
    return target<source ? target=source,1 : 0;
}
const int mn=1e5+11;
const int inf=0x3f3f3f3f3f3f3f3f;

int n,s;
int a[mn],b[mn];
int def_a[mn],def_b[mn];
int l[mn],r[mn];
int cc[mn];

ii t[mn];
int mval[mn];

int tmp[mn];

void build_interval(int x){
    //build the x_th interval

    t[r[x]]=ii(a[r[x]],b[r[x]]);
    for(int i=r[x]-1;i>=l[x];i--)
        t[i]=ii(t[i+1].first+a[i],t[i+1].second+b[i]);

    sort(t+l[x],t+r[x]+1,greater<ii>());

    mval[l[x]]=t[l[x]].second;
    for(int i=l[x]+1;i<=r[x];i++)
        mval[i]=min(mval[i-1],t[i].second);
}

int find(int x,int cur){
    int lo=l[x],hi=r[x],ans=-1;
    while(lo<=hi){
        int mid=(lo+hi>>1);
        if(t[mid].first>=cur)ans=mid,lo=mid+1;
        else hi=mid-1;
    }
    return ans==-1 ? inf : mval[ans];
}
int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
	#ifdef _TPR_
		freopen("t.inp","r",stdin);
		freopen("t.out","w",stdout);
	#endif
    
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    
    int EPS=sqrt(n);

    for(int i=1;EPS*(i-1)+1<=n;i++){
        l[i]=EPS*(i-1)+1;
        r[i]=min(EPS*i,n);

        for(int j=l[i];j<=r[i];j++){
            cc[j]=i;
            def_a[i]+=a[j];
            def_b[i]+=b[j];
        }
    }

    for(int i=1;i<=cc[n];i++)build_interval(i);

    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int i,x,y;cin>>i>>x>>y;
            def_a[cc[i]]+=x-a[i];
            def_b[cc[i]]+=y-b[i];
            a[i]=x;b[i]=y;
            build_interval(cc[i]);
        }else{
            int i;cin>>i;
            int cur=l[cc[i]],cur_ta=0,cur_tb=0;
            int res=inf;
            for(;i>=cur;i--){
                cur_ta+=a[i];
                cur_tb+=b[i];
                if(cur_ta>=s)ckmin(res,cur_tb);
            }
            for(int x=cc[cur]-1;x>=1;x--){
                int eval=find(x,s-cur_ta);
                if(eval!=inf)
                    ckmin(res,find(x,s-cur_ta)+cur_tb);
                cur_ta+=def_a[x];
                cur_tb+=def_b[x];
            }
            cout<<(res==inf ? -1 : res)<<'\n';
        }
    }
}