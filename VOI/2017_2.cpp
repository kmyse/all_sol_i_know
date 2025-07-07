#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix
{
    ll val[2][2];
};
ll MOD;
matrix a,b,c,y,z;
ll n,k,i,a1,c1,b1,id,x[1000005];
unordered_map<ll,ll>mp;
vector<ll>v;
matrix operator*(matrix a,matrix b)
{
    matrix c;
    for(ll i=0;i<2;++i)
        for(ll j=0;j<2;++j)
        {
            c.val[i][j]=0;
            for(ll k=0;k<2;++k)
                c.val[i][j]=(c.val[i][j]%MOD+(a.val[i][k]%MOD*b.val[k][j]%MOD)%MOD)%MOD;
        }
    return c;
}
matrix divide_and_conquer(matrix a,ll k)
{
    if(k==1)
        return a;
    matrix b=divide_and_conquer(a,k/2);
    if(k%2==0)
        return b*b;
    else
        return b*b*a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin>>q;
    while(q--)
    {
        v.clear();
        cin>>n>>id>>MOD;
        a.val[0][0]=1;
        a.val[1][0]=1;
        a.val[0][1]=1;
        a.val[1][1]=0;
        c.val[0][0]=1;
        c.val[0][1]=1;
        if(id==1)
        {
            x[0]=0;
            x[1]=1;
        }
        else if(id==2)
        {
            x[0]=1;
            x[1]=1;
        }
        else
        {
            b=divide_and_conquer(a,id-2);
            b=c*b;
            x[0]=b.val[0][1];
            x[1]=b.val[0][0];
        }
        for(i=2;i<=n;i++)
        {
            x[i]=(x[i-1]+x[i-2])%MOD;
        }
        ll sum=0;
        mp[sum]=0;
        for(i=1;i<=n;i++)
        {
            sum+=x[i];
            ll mm=sum%MOD;
            if(mp.find(mm)!=mp.end())
            {
                ll be=mp[mm]+1;
                for (ll j=be;j<=i;++j)
                {
                    v.push_back(j);
                }
                break;
            }
            mp[mm]=i;
        }
        mp.clear();
        cout<<v.size()<<" ";
        if(v.size()!=0)
        for(i=0;i<v.size();i++)
            cout<<v[i]+id-1<<" ";
        cout<<'\n';
        // 3 5 8 13
    }




}
