#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
const ll MOD=1e9+7;
using namespace std;
ll a[20][20],dp[1<<10+1][1001],i,j,n,m;
void collumn_traversing(ll pos,ll col,ll mask,ll nmask)
{
    if(pos==n)
    {
        dp[nmask][col+1]=(dp[nmask][col+1]+dp[mask][col])%MOD;
        return;
    }
    if(pos+1<n&&((1<<pos)&mask)==0&&((1<<(pos+1))&mask)==0)
        collumn_traversing(pos+2,col,mask,nmask);
    if(((1<<pos)&mask)==0)
        collumn_traversing(pos+1,col,mask,nmask+(1<<pos));
    if(((1<<pos)&mask)!=0)
        collumn_traversing(pos+1,col,mask,nmask);
}
signed main()
{
    cin>>n>>m;
    dp[0][0]=1;
    for(i=0;i<m;i++)
        for(j=0;j<(1<<n);j++)
        {
            if(dp[j][i]>0)
                collumn_traversing(0,i,j,0);
        }
    cout<<dp[0][m]%MOD;


}
