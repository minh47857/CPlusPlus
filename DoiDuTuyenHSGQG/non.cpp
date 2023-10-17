#include<bits/stdc++.h>
using namespace std;
/// Created by A2k49 ///
long long a, n, i, j;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
    for( i = 1; i <= n; i++)
    {
        cin >> a;
        for(j = sqrt(a); j >= 1; j--)
        {
            if(a%(j*j)==0)
            {
            	cout<<j<<?" "<<a/(j*j)<<'\n';
            	break;
			}
        }
        
    }
	return 0;
}
