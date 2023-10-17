#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define FOR(i,x,y) for(int i=x;i<=y;i++)
#define FOD(i,x,y) for(int i=x;i>=y;i--)
const ll N=155;
const ll MOD=0;
const ll oo=1e15;

int n;
int extra,ex;
ll num,temp1,temp2,ans=oo,res=0;
char s[N];
bool check;

int main(){
	freopen("TABLE.inp","r",stdin);
	freopen("TABLE.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n;
	FOR(i,1,n) cin>>s[i];

	FOR(i,1,n){
		num=0;
		FOR(j,i,n){
			num=num*10+s[j]-'0';
			temp1=num;
			check=1;
//			if(num==123) cout<<temp1<<"\n";
			if(i>=2){
				for(int t=i-1;t>=1;t-=(j-i+1)){
					temp2=0;
					FOR(k,max(1,t-(j-i)),t){
						temp2=temp2*10+s[k]-'0';
					}
//					if(num==123) cout<<" "<<temp2<<"\n";
	//				cout<<temp1<<"\n";
					if(t-(j-i)<1){
//						if(num==123) cout<<(temp1-1)%(int)pow(10,t)<<"\n";
						if(temp2!=(temp1-1)%(int)pow(10,t)) {check=0; break;}
						else continue;
					}
					if(temp2==temp1-1) {temp1--; continue;}
					else{check=0; break;}
				}
			}
			
//			if(num==123) cout<<check<<"\n";
			
			temp1=num;
			for(int t=j+1;t<=n;t+=(j-i+1)){
				temp2=0;
				FOR(k,t,min(n,t+(j-i))){
					temp2=temp2*10+s[k]-'0';
				}
//				if(num==123) cout<<temp2<<"\n";
//				cout<<temp1<<"\n";
				if(t+(j-i)>n){
//					if(num==123) cout<<temp2<<" "<<(temp1+1)/(int)pow(10,j-i-n+t)<<" ";
					if(temp2==(temp1+1)/(int)pow(10,j-i-n+t)) extra=(n-t+1);
					else{check=0; break;}
					continue;
				}
				if(temp2==temp1+1) {temp1++; continue;}
				else{check=0; break;}
			}
//			if(num==123) cout<<check<<"\n";
//			if(num==123) cout<<"\n";
			if(check==1){
				ans=min(ans,temp1);
				if(ans==temp1) ex=extra;
			}
		}
	}
	
//	cout<<ans<<" "<<ex<<"\n";
	
	if(ans==oo) cout<<-1;
	
	num=ans;
	int cnt=0;
	while(num>0){num/=10; cnt++;}
//	cout<<cnt<<"\n";
	
	FOR(i,1,cnt-1){
		res+=i*((int)pow(10,i)-(int)pow(10,i-1));
//		cout<<(int)pow(10,i)-1<<" "<<(int)pow(10,i-1)<<"\n";
	}
//	cout<<ans<<" "<<(int)pow(10,cnt-1)<<"\n";
	res+=cnt*(ans-(int)pow(10,cnt-1)+1);
	
	cout<<res+ex;
	return 0;
}

