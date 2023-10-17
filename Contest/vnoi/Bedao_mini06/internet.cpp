#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 727355608 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll a , b , c , d , mu4 , s , ans[N] , res , dem = 0;
bool check2()
{
	for (int i = 1 ; i <= s / 2; i++) if(ans[i] != ans[s - i + 1]) return false;
	return true; 
}
int main()
{
 cin >> s >> a >> b >> c;
 d = s - a - b - c;
 for(int i = 2 ; i <= a ; i += 2)
 {
 //	cout << "?";
 	ans[++dem] = 1;
 	ans[s - dem + 1] = 1;
 //	cout << dem <<  ' ' << s - dem + 1 << endl;
 	if (i == 2)
 	{
 		for (int j = 2 ; j <= d ; j += 2)
 		{
 			ans[++dem] = 0;
 			ans[s - dem + 1] = 0;
 		//	cout << dem <<  ' ' << s - dem + 1 << endl;
		}
	}
 }
// for (int i = 1 ; i <= s ; i++) cout << ans[i] << ' ';
// cout << endl;
 for(int i = 2 ; i <= b ; i += 2)
 {
 //	cout << "?";
 	ans[++dem] = 2;
 	ans[s - dem + 1] = 2;
 //	cout << dem <<  ' ' << s - dem + 1 << endl;
 	if (i == 2 && a == 0)
 	{
 		for (int j = 2 ; j <= d ; j += 2)
 		{
 			ans[++dem] = 0;
 			ans[s - dem + 1] = 0;
 		//	cout << dem <<  ' ' << s - dem + 1 << endl;
		}
	}
 }
  for(int i = 2 ; i <= c ; i += 2)
 {
 //	cout << "?";
 	ans[++dem] = 3;
 	ans[s - dem + 1] = 3;
 //	cout << dem <<  ' ' << s - dem + 1 << endl;
 	if (i == 2 && a == 0 && b == 0)
 	{
 		for (int j = 2 ; j <= d ; j += 2)
 		{
 			ans[++dem] = 0;
 			ans[s - dem + 1] = 0;
 		//	cout << dem <<  ' ' << s - dem + 1 << endl;
		}
	}
 }
 if(s % 2)
 {
    	if(a % 2) ans[++dem] = 1;
    	if(b % 2) ans[++dem] = 2;
    	if(c % 2) ans[++dem] = 3;
    	if(d % 2) ans[++dem] = 0;
 }
 if(check2() == false) 
 {
 	cout << "Bedao!";
 	return 0;
 }
 res = ans[1];
 mu4 = 1;
 for (int i = 2 ; i <= s ; i++)
 {
 //	cout << ans[i] << ' ';
 	mu4 = (mu4 * 4) % MOD;
 	res = (res + ans[i] * mu4) % MOD;
 }
 cout <<res ;
 return 0;
}

