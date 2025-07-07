#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define getbit(x,i) (((x)>>(i))&1ULL)
#define biton(x,i) ((x)(1ULL<<(i)))
#define bitoff(x,i) ((x)&(~(1ULL<<(i))))
#define flipbit(x,i) ((x)^(1ULL<<(i)))
#define umpll unordered_map<ll,ll>
#define umpstr unordered_map<string,ll>
#define mppii map<pii,ll>
#define f(n,st,k) for(ll i=(st);i<=(n);i+=(k))
#define rf(n,st,k) for(ll i=(st);i>=(n);i-=(k))
using namespace std;
bool check[1501];
ll dp[20][11][2];
ll cnt(ll i,ll digit,bool k,bool check0,vector<ll>num)
{
    if(num.empty())
        return 0;
    if(i<0)
        return 1;
    if(k&&dp[i][digit][check0]!=-1)
        return dp[i][digit][check0];
    ll lim=(k==0)?num[i]:9;
    ll num_cnt=0;
    for(ll d=0;d<=lim;d++)
    {
        if(check0&&d==0)
            num_cnt+=cnt(i-1,10,k||d<num[i],1,num);
        else
        {
            if(d==digit)
                continue;
            num_cnt+=cnt(i-1,d,k||d<num[i],0,num);
        }
    }
    if(k)
        dp[i][digit][check0]=num_cnt;
    return num_cnt;
}
vector<ll>ld,rd;
void trans(ll n,vector<ll>&d)
{
    d.clear();
    if(n<0)
        return;
    if(n==0)
        d.push_back(0);
    while(n>0)
    {
        d.push_back(n%10);
        n/=10;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(".inp","r"))
    {
        freopen(".inp","r",stdin);
        freopen(".out","w",stdout);
    }
    ll l,r,t;
    t=1;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        cin>>l>>r;
        trans(l-1,ld);
        trans(r,rd);
        cout<<cnt(rd.size()-1,10,0,1,rd)-cnt(ld.size()-1,10,0,1,ld);
    }
}
