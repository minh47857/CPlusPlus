#include <bits/stdc++.h>

using namespace std;

int const maxN=15e1;
int const maxD=16;

using Arr=array<int,maxD>;

int N;
char c[maxN+3];
int a[maxN+3];

int64_t Pow10(int x){
    int64_t ans=1;
    while(x--){
        ans*=10;
    }
    return ans;
}

int digits(int64_t x){
    int ans=0;
    do{
        ++ans;
        x/=10;
    }
    while(x);
    return ans;
}

int64_t Get(int p,int d){
    int64_t ans=0;
    for(;d;--d){
        ans*=10;
        ans+=a[p++];
    }
    return ans;
}

int64_t Count(int64_t x){
    int64_t ans=0;
    int64_t lst=1;
    while(lst*10<x){
        ans+=((lst*10)-lst)*digits(lst);
        lst*=10;
    }
    ans+=(x-lst+1)*digits(lst);
    return ans;
}

int64_t Get(int dig,Arr&arr){
    int64_t ans=0;
    for(int i=0;i<dig;++i){
        ans*=10;
        ans+=arr[i];
    }
    return ans;
}

Arr Add_one(int dig,Arr arr){
    int tmp=1;
    for(int i=dig-1;i>=0;--i){
        arr[i]+=tmp;
        tmp=arr[i]/10;
        arr[i]%=10;
    }
    return arr;
}

int64_t result=-1;

void Upd_res(int64_t x){
    if(result==-1||x<result){
        result=x;
    }
    return ;
}

void Reset(int dig,Arr&arr){
    for(int i=0;i<dig;++i){
        arr[i]=0;
    }
    return ;
}

void Print(int dig,Arr&arr){
    for(int i=0;i<dig;++i){
        cout<<arr[i];
    }
    cout<<'\n';
    return ;
}

void Solve(){
    for(int i=0;i<N;++i){
        a[i]=c[i]-'0';
    }
    for(int i=1;i<=maxD;++i){
        for(int j=0;j<=maxD-i;++j){
            int rem=N-i;
            int dig=i+j;
            if(dig>N){
                continue;
            }
            if(!rem){
                if(!a[0]){
                    continue;
                }
                Upd_res(Count(Get(0,dig)));
                continue;
            }
            Arr pre,cur;
            Reset(dig,pre);
            Reset(dig,cur);
            int64_t cnt;
            int pos=0;
            bool ok=true;
            bool is_fir=true;
            while(1){
                    //Print(dig,pre);
                    if(pos>=N){
                        break;
                    }
                    if(!pos){
                        for(int d=dig,p=pos+i;d;--d,--p){
                            pre[d-1]=a[p-1];
                        }
                        pos+=i;
                        continue;
                    }
                    if(!a[pos]){
                        ok=false;
                        break;
                    }
                    Reset(dig,cur);
                    if(pos+dig<=N){
                        for(int d=dig,p=pos+dig;d;--d,--p){
                            cur[d-1]=a[p-1];
                        }
                        Arr tmp=Add_one(dig,pre);
                        //cout<<i<<' '<<j<<'\n';
                        //cout<<"tmp=";Print(dig,tmp);
                        //Print(dig,cur);
                        //cout<<is_fir<<'\n';
                        for(int d=0;d<dig;++d){
                            if(is_fir&&d<j){
                                continue;
                            }
                            if(tmp[d]!=cur[d]){
                                //cout<<d<<' '<<tmp[d]<<' '<<cur[d]<<'\n';
                                ok=false;
                                break;
                            }
                        }
                        is_fir=false;
                        pos+=dig;
                        pre=cur;
                        cnt=Count(Get(dig,cur));
                    }
                    else{
                        int len=N-pos;
                        for(int d=0,p=pos;d<dig&&p<N;++d,++p){
                            cur[d]=a[p];
                        }
                        Arr tmp=Add_one(dig,pre);
                        //Print(dig,tmp);
                        Arr now;
                        for(int d=0;d<dig;++d){
                            if((is_fir&&d<j)||(d>=len)){
                                continue;
                            }
                            if(tmp[d]!=cur[d]){
                                ok=false;
                                break;
                            }
                        }
                        for(int d=0;d<dig;++d){
                            if(d<len){
                                now[d]=cur[d];
                            }
                            else{
                                now[d]=tmp[d];
                            }
                        }
                        is_fir=false;
                        pos+=dig;
                        pre=cur;
                        cnt=Count(Get(dig,now)-1)+len;
                    }
                    if(!ok){
                        break;
                    }
            }
            if(ok){
                    //cout<<ok<<' '<<cnt<<'\n';
                Upd_res(cnt);
            }
            //cout<<i<<' '<<j<<' '<<ok<<' '<<result<<'\n';
        }
    }
    cout<<result;
    return ;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>N>>c;
    Solve();
    return 0;
}
